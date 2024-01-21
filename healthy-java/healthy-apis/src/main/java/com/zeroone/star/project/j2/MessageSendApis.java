package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageSendDTO;
import com.zeroone.star.project.j2.query.MessageSendQuery;
import com.zeroone.star.project.j2.query.MessageSendUnRead;
import com.zeroone.star.project.vo.JsonVO;

public interface MessageSendApis {
    //获取最新未读消息列表
    JsonVO<PageDTO<MessageSendDTO>> queryMessageSendUnRead(Integer status);


    //获取消息详情
    JsonVO<PageDTO<MessageSendDTO>> queryMessageSend(MessageSendQuery messageSendQuery);

    //修改消息状态
    JsonVO<PageDTO<MessageSendDTO>> updateMessageSend(MessageSendDTO messageSendDTO);


}
