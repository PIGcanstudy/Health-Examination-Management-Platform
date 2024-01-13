package com.zeroone.star.percenter.controller;

import com.zeroone.star.project.j1.percenter.SecuritySettingApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/security-setting")
@Api(tags = "安全设置")
public class SecuritySettingController implements SecuritySettingApis {
}
