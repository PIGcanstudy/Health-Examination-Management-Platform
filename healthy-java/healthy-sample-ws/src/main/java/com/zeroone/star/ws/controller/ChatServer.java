package com.zeroone.star.ws.controller;

import org.springframework.stereotype.Component;

import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;
import java.util.concurrent.ConcurrentHashMap;

/**
 * <p>
 * 描述：聊天服务器
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@ServerEndpoint("/chat")
@Component
public class ChatServer {
    /**
     * 声明一个连接会话池
     */
    private static final ConcurrentHashMap<String, Session> SESSION_POOL = new ConcurrentHashMap<>();

    @OnOpen
    public void onOpen(Session session) throws IOException {
        // 判断客户对象是否存在
        String clientId = session.getQueryString();
        if (SESSION_POOL.containsKey(clientId)) {
            CloseReason closeReason = new CloseReason(CloseReason.CloseCodes.CANNOT_ACCEPT, "ID冲突，连接拒绝");
            session.getUserProperties().put("cr", closeReason);
            session.close();
            return;
        }
        // 将客户对象存储到池中
        SESSION_POOL.put(clientId, session);
        System.out.println("客户端[" + clientId + "] 开启连接");
    }

    @OnMessage
    public String onMessage(String msg, Session session) throws IOException {
        // 解析消息 => ID::消息内容
        String[] msgArr = msg.split("::", 2);   // 根据::将字符串拆成两部分
        // 群发消息
        if ("all".equalsIgnoreCase(msgArr[0])) {
            for (Session one : SESSION_POOL.values()) {
                // 排除自己
                if (one == session) {
                    continue;
                }
                // 发送消息
                one.getBasicRemote().sendText(msgArr[1]);
            }
        }
        // 指定发送
        else {
            // 获取消息接收对象
            Session target = SESSION_POOL.get(msgArr[0]);
            if (target != null) {
                target.getBasicRemote().sendText(msgArr[1]);
            }
        }
        return session.getQueryString() + "：消息发送成功";
    }

    @OnClose
    public void onClose(Session session) {
        String clientId = session.getQueryString();
        // 如果是拒绝连接触发的关闭，不做处理（在onOpen中已经处理了）
        Object crObj = session.getUserProperties().get("cr");
        if (crObj != null) {
            CloseReason cr = (CloseReason) crObj;
            if (cr.getCloseCode() == CloseReason.CloseCodes.CANNOT_ACCEPT) {
                System.out.println("拒绝客户端["+ clientId +"]：关闭连接");
                return;
            }
        }
        // 从会话池中移除
        SESSION_POOL.remove(clientId);
        System.out.println("客户端["+ clientId +"]：关闭连接");
    }

    @OnError
    public void onError(Session session, Throwable throwable) {
        System.out.println("客户端["+ session.getQueryString() +"]：错误信息，" + throwable.getMessage());
    }
}
