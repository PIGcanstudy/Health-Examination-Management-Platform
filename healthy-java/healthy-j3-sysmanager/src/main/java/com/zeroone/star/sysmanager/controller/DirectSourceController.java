package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j3.dictory.DirectSourceApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * 字典数据controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:04
 **/
@RestController
@RequestMapping("/j3-directSource")
@Api("字典数据")
public class DirectSourceController implements DirectSourceApis {
}
