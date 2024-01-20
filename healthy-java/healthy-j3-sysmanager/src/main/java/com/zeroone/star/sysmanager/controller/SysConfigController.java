package com.zeroone.star.sysmanager.controller;


import com.zeroone.star.project.j3.sysconfig.SysConfigApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * 系统配置Controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:10
 **/
@RestController
@RequestMapping("/j3-sysConfig")
@Api("系统配置")
public class SysConfigController implements SysConfigApis {
}
