package com.zeroone.star.message.controller;


import com.zeroone.star.project.j2.MessageApis;
import com.zeroone.star.project.vo.JsonVO;
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
public class TMessageController implements MessageApis {

    @Override
    public JsonVO<Object> removeMessage(String[] ids) {
        return null;
    }
}

