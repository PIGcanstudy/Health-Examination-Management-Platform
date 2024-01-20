package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.MsgListQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.SendMsgQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.UpdateMsgQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;
import com.zeroone.star.sysmanager.entity.Message;
import com.zeroone.star.sysmanager.entity.MessageSend;
import com.zeroone.star.sysmanager.entity.ProType;
import com.zeroone.star.sysmanager.mapper.MessageMapper;
import com.zeroone.star.sysmanager.mapper.MessageSendMapper;
import com.zeroone.star.sysmanager.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.apache.poi.ss.formula.functions.T;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

/**
 * <p>
 * 消息 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */

@Service
public class TMessageServiceImpl extends ServiceImpl<MessageMapper, Message> implements ITMessageService {

    @Resource
    private MessageSendMapper messageSendMapper;
    /**
     * @description:消息详情业务
     * @author: 坚强少年
     * @date: 2024/1/17 17:05
     * @param: [detailDTO]
     * @return: com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.message.MessageDTO>
     **/
    @Override
    public PageDTO<MessageResponseDTO> selectMessageDetailPage(MessageSendDTO messageSend) {
        Page page = new Page(messageSend.getPageIndex(),messageSend.getPageSize());
        LambdaQueryWrapper<MessageSend> wrapper = new LambdaQueryWrapper<>();
        if (messageSend.getUserId() != null){
            wrapper.eq(MessageSend::getUserId,messageSend.getUserId());
        }
        page = messageSendMapper.selectPage(page, wrapper);
        PageDTO<MessageResponseDTO> message = PageDTO.create(page);
        return message;
    }

    @Resource
    private MessageMapper messageMapper;
    @Override
    public PageDTO<MsgListDTO> queryMessageList(MsgListQuery msgListQuery) {
        //构建分页条件对象
        Page page = new Page(msgListQuery.getPageIndex(),msgListQuery.getPageSize());

        //查询条件
        LambdaQueryWrapper<Message> wrapper = new LambdaQueryWrapper<>();
        if (msgListQuery.getMsgTitle()!= null){
            wrapper.eq(Message::getTitle,msgListQuery.getMsgTitle());
        }
        if (msgListQuery.getMsgType() != null ) {
            wrapper.eq(Message::getType,msgListQuery.getMsgType());
        }
        if (msgListQuery.getMsgContent() != null) {
            wrapper.like(Message::getContent,msgListQuery.getMsgContent());
        }
        if (msgListQuery.getCreateTime()!= null) {
            wrapper.like(Message::getCreateTime,msgListQuery.getCreateTime());
        }
        //执行查询
        Page result = messageMapper.selectPage(page, wrapper);

        //PageDTO.create() 可以将分页插件的page对象转换成当前pageDto对象
        PageDTO<MsgListDTO> message = PageDTO.create(result);
        return message;
    }


    @Override
    public JsonVO<Boolean> sendMsg(SendMsgQuery sendMsgQuery) {
        Message message = new Message();
        message.setTitle(sendMsgQuery.getId());
        message.setCreateBy(sendMsgQuery.getCreateBy());

//        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
//        LocalDateTime localDateTime = LocalDateTime.parse(sendMsgQuery.getCreateTime(), formatter);
//        message.setCreateTime(localDateTime);

        message.setCreateTime(sendMsgQuery.getCreateTime());
        message.setType(sendMsgQuery.getType());
        message.setTitle(sendMsgQuery.getTitle());
        message.setContent(sendMsgQuery.getContent());
        message.setCreateSend(sendMsgQuery.getCreateSend());
        //执行修改
        boolean success = messageMapper.insert(message) > 0;
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }



    @Override
    public JsonVO<Boolean> updateMsg(UpdateMsgQuery updateMsgQuery) {
        //获取元消息
        Message message = messageMapper.selectById(updateMsgQuery.getId());

        //构建更新条件
        LambdaUpdateWrapper<Message> wrapper = new LambdaUpdateWrapper<>();
        if (updateMsgQuery.getUpdateByID()!= null){
            wrapper.eq(Message::getUpdateBy,message.getUpdateBy()).set(Message::getUpdateBy,updateMsgQuery.getUpdateByID());
        }
        if (updateMsgQuery.getUpdateTime()!= null){
            wrapper.eq(Message::getUpdateTime,message.getUpdateTime()).set(Message::getUpdateTime,updateMsgQuery.getUpdateTime());
        }
        if (updateMsgQuery.getType()!= null){
            wrapper.eq(Message::getType,message.getType()).set(Message::getType,updateMsgQuery.getType());
        }
        if (updateMsgQuery.getTitle()!= null){
            wrapper.eq(Message::getTitle,message.getTitle()).set(Message::getTitle,updateMsgQuery.getTitle());
        }
        if (updateMsgQuery.getContent()!= null){
            wrapper.eq(Message::getContent,message.getContent()).set(Message::getContent,updateMsgQuery.getContent());
        }
        if (updateMsgQuery.getCreateSend()!= null){
            wrapper.eq(Message::getCreateSend,message.getCreateSend()).set(Message::getCreateSend,updateMsgQuery.getCreateSend());
        }
        //执行修改
        boolean success = messageMapper.update(null, wrapper) > 0;
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }
}
