package com.zeroone.star.project.j3.message;

import com.zeroone.star.project.dto.j3.message.EditMessageDTO;
import com.zeroone.star.project.dto.j3.message.SendMessageDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @description:消息管理Api
 * @author: 坚强少年
 * @date: 2024/1/15 20:36
 **/
public interface MessageApis {

    /**
     * 发送消息
     * @param sendMessageDTO
     * @return
     */
    JsonVO<String> sendMessage(SendMessageDTO sendMessageDTO);

    /**
     * 修改消息
     * @param editMessageDTO
     * @return
     */
    JsonVO<String> editMessage(EditMessageDTO editMessageDTO);
}
