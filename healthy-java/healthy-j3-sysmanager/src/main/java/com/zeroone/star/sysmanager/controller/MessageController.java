package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.j3.message.EditMessageDTO;
import com.zeroone.star.project.dto.j3.message.SendMessageDTO;
import com.zeroone.star.project.j3.message.MessageApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.validation.Valid;

/**
 * 消息管理Controller
 *
 * @author ZhangJF
 * @date 2024/01/15 21:57
 **/
@RestController
@RequestMapping("/j3-message")
@Api("消息控制")
public class MessageController implements MessageApis {

    @ApiOperation("发送消息")
    @PostMapping("send-Message")
    @Override
    public JsonVO<String> sendMessage(@Valid @RequestBody SendMessageDTO sendMessageDTO) {
        return null;
    }

    @ApiOperation("修改消息")
    @PostMapping("edit-Message")
    @Override
    public JsonVO<String> editMessage(@Valid @RequestBody EditMessageDTO editMessageDTO) {
        return null;
    }
}
