package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageDTO;
import com.zeroone.star.project.dto.j3.message.SearchMessageDetailDTO;
import com.zeroone.star.project.j3.message.MessageApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.ITMessageService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;


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
    @Override
    public JsonVO<Boolean> deleteByIds(Long id) {
        return null;
    }

    @ApiOperation("获取消息详情页列表")
    @GetMapping("/queryMessageDetail")
    @Override
    public JsonVO<PageDTO<SearchMessageDetailDTO>> queryMessageDetail(PageDTO<MessageDTO> detailDTO) {
        PageDTO<SearchMessageDetailDTO> page = messageService.queryMessageDetail(detailDTO);
        return JsonVO.success(page);
    }

}
