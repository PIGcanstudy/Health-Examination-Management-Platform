package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j3.dto.MessageDTO;
import com.zeroone.star.project.j3.message.MessageApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

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

}
