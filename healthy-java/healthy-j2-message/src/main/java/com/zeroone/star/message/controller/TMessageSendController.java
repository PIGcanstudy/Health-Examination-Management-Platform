package com.zeroone.star.message.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.MessageApis;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 消息发送 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@Api(tags = "消息详情")
@RequestMapping("/message/t-message-send")
public class TMessageSendController {
    @ApiOperation("获取消息详情")
    @GetMapping("MessageSend")
    public JsonVO<PageDTO<MessageDTO>> queryMessage(MessageQuery messageQuery) {
        return null;
    }
}

