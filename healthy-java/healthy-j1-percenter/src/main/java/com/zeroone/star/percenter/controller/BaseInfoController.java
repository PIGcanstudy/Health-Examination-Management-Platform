package com.zeroone.star.percenter.controller;

import com.zeroone.star.project.j1.percenter.BaseInfoApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/base-info")
@Api(tags = "基本信息")
public class BaseInfoController implements BaseInfoApis {
}
