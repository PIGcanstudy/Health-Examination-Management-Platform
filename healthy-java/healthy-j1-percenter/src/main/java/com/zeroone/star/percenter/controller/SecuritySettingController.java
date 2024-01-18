package com.zeroone.star.percenter.controller;

import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.percenter.SecuritySettingApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/security-setting")
@Api(tags = "安全设置")
public class SecuritySettingController implements SecuritySettingApis {
    @ApiOperation(value = "修改密码", notes = "用户修改自己的密码")
    @PostMapping("/changePassword")
    @Override
    public JsonVO<String> changePassword(@RequestBody ModifyPasswordDTO modifyPasswordDTO) {
        System.out.println("修改密码");
        return JsonVO.success("修改成功");
    }
    @ApiOperation(value = "修改手机号", notes = "用户修改自己的手机号码")
    @PostMapping("/changePhone")
    @Override
    public JsonVO<String> changePhone(@RequestBody ModifyPhoneDTO modifyPhoneDTO) {
        System.out.println("修改手机号");
        return JsonVO.success("修改成功");
    }
}
