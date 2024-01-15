package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j3.sysconfig.SysConfigApis;
import com.zeroone.star.project.j3.typelib.TypeLibApis;
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
@RequestMapping("/j3-typeLib")
@Api("类型库")
public class TypeLibController implements TypeLibApis {
}
