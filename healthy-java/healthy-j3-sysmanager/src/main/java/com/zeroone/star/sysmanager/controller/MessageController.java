package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.j3.message.MessageApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.ITMessageService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.ArrayList;


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
    private ITMessageService messageService;

    @DeleteMapping("/deleteByIds")
    @Override
    public JsonVO<Boolean> deleteByIds(@RequestParam ArrayList<String> ids) {
        boolean success = messageService.removeByIds(ids);
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }

    @ApiOperation("获取消息详情页列表")
    @GetMapping("/queryMessageDetail")
    @Override
    public JsonVO<PageDTO<MessageResponseDTO>> selectMessageDetailPage(MessageSendDTO messageSend) {
        return messageService.getJsonVO(messageSend);
    }
}
