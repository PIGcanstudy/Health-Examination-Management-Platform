package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.j1.dto.ChangePasswordDTO;
import com.zeroone.star.project.j1.sysmanager.UserPasswordApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-用户密码")
@Validated
public class UserPasswordController implements UserPasswordApis {

    @Override
    @PostMapping("/modify-password")
    @ApiOperation("更改密码接口")
    public JsonVO updatePassword(@Validated @RequestBody ChangePasswordDTO changePasswordDTO) {
        return JsonVO.success("修改密码成功");
    }
}
