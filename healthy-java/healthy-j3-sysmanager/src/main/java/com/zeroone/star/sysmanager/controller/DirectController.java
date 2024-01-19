package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j3.direct.DirectApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * 字典controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:04
 **/
@RestController
@RequestMapping("/j3-direct")
@Api("字典")
public class DirectController implements DirectApis {
}
