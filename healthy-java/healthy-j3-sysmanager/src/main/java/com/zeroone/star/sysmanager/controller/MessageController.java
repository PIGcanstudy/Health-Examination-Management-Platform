package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.MessageDTO;
import com.zeroone.star.project.dto.j3.message.EditMessageDTO;
import com.zeroone.star.project.dto.j3.message.SendMessageDTO;
import com.zeroone.star.project.j3.message.MessageApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.MessageService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

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

    @Resource
    private MessageService messageService;
    @Override
    public JsonVO<Boolean> deleteByIds(Long id) {
        return null;
    }

    @ApiOperation("获取消息详情页列表")
    @GetMapping("/queryMessageDetail")
    @Override
    public JsonVO<PageDTO<MessageDTO>> queryMessageDetail(PageDTO<MessageDTO> detailDTO) {
        PageDTO<MessageDTO> page = messageService.queryMessageDetail(detailDTO);
        return JsonVO.success(page);
    }
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
