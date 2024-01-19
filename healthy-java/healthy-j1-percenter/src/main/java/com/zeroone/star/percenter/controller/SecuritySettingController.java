package com.zeroone.star.percenter.controller;

import com.zeroone.star.project.j1.dto.percenter.GetSmsCodeDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyEmailDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.percenter.SecuritySettingApis;
import com.zeroone.star.project.j1.vo.percenter.ModifyEmailVO;
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
    @PostMapping("/change-password")
    @Override
    public JsonVO<String> changePassword(@RequestBody ModifyPasswordDTO modifyPasswordDTO) {
        System.out.println("修改密码");
        return JsonVO.success("修改成功");
    }
    @ApiOperation(value = "修改手机号", notes = "用户修改自己的手机号码")
    @PostMapping("/change-phone")
    @Override
    public JsonVO<String> changePhone(@RequestBody ModifyPhoneDTO modifyPhoneDTO) {
        System.out.println("修改手机号");
        return JsonVO.success("修改成功");
    }

    @ApiOperation(value = "修改邮箱", notes = "用户修改自己的邮箱")
    @PostMapping("/change-email")
    @Override
    public JsonVO<ModifyEmailDTO> changeEmail(ModifyEmailVO modifyEmailVO) {
        return JsonVO.success(null);
    }

//    @ApiOperation(value = "获取短信验证码")
//    @PostMapping("/get-sms-code")
//    @Override
//    public JsonVO<GetSmsCodeDTO> getSmsCode(ModifyPhoneVO modifyPhoneVO) {
//        GetSmsCodeDTO getSmsCodeDTO = new GetSmsCodeDTO();
//        return JsonVO.success(getSmsCodeDTO);
//    }
}
