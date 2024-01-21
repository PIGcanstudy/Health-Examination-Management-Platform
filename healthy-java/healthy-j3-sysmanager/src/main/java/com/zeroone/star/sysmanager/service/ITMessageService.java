package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.Message;

import java.util.List;

/**
 * <p>
 * 消息 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITMessageService extends IService<Message> {

    PageDTO<MessageResponseDTO> selectMessageDetailPage(MessageSendDTO messageSend);

    JsonVO<PageDTO<MessageResponseDTO>> getJsonVO(MessageSendDTO messageSend);
}
