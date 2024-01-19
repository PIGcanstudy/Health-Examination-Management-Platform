package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageDetailDTO;
import com.zeroone.star.sysmanager.entity.Message;

/**
 * <p>
 * 消息 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITMessageService extends IService<Message> {

    PageDTO<MessageDetailDTO> queryMessageDetail(MessageDetailDTO detailDTO);
}
