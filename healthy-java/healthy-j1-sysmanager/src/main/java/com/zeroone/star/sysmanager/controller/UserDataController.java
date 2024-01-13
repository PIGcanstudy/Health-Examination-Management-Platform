package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j1.sysmanager.UserDataApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-用户数据")
public class UserDataController implements UserDataApis {
}
