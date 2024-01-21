package com.zeroone.star.message.controller;


import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 消息 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@RequestMapping("/message/t-message")
public class TMessageController {
    @ApiOperation("获取消息列表")
    @GetMapping("MessageQueryAll")
    @Override
    public JsonVO<PageDTO<MessageDTO>> queryMessageAll(MessageQuery messageQuery) {
        return null;
    }

    @ApiOperation(value = "删除消息")
    @DeleteMapping("remove-by-ids")
    @Override
    public JsonVO<Object> removeMessage(@RequestParam String[] ids) {
        return null;
    }

    @ApiOperation(value = "刷新系统公告")
    @GetMapping("query-by-id")
    @Override
    public JsonVO<MessageDTO> queryMessage(@RequestParam String id) {
        return null;
    }
}

