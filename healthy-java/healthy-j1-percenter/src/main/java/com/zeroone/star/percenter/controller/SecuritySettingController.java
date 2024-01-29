package com.zeroone.star.percenter.controller;


import com.zeroone.star.percenter.service.ITUserService;
import com.zeroone.star.project.j1.dto.percenter.EmailDTO;
import com.zeroone.star.project.j1.dto.percenter.GetSmsCodeDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.percenter.SecuritySettingApis;
import com.zeroone.star.project.j1.query.percenter.EmailCodeQuery;
import com.zeroone.star.project.j1.query.sysmanager.PasswordAuthenticationQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;



@RestController
@RequestMapping("/security-setting")
@Api(tags = "安全设置")
@Validated
public class SecuritySettingController implements SecuritySettingApis {
    @Autowired
    private ITUserService userService;

    /**
     * 密码身份验证
     * @param passwordAuthenticationQuery 密码身份验证传入的数据
     * @return
     */
    @Override
    @GetMapping("/password-authentication")
    @ApiOperation("密码身份验证")
    public JsonVO<String> passwordAuthentication(@Validated PasswordAuthenticationQuery passwordAuthenticationQuery){
        userService.passwordAuthentication(passwordAuthenticationQuery.getPassword());
        return JsonVO.success("密码验证成功");
    }

    /**
     * 用户修改自己的密码
     *
     * @param modifyPasswordDTO 修改密码视图对象
     * @return
     */
    @ApiOperation(value = "修改密码", notes = "用户修改自己的密码")
    @PostMapping("/change-password")
    @Override
    public JsonVO<String> changePassword(@RequestBody @Validated ModifyPasswordDTO modifyPasswordDTO) {
        return userService.modifyPassword(modifyPasswordDTO);
    }

    /**
     * 用户修改自己的手机号码
     *
     * @param modifyPhoneDTO 修改手机号视图对象
     * @return
     */
    //@ApiOperation(value = "修改手机号", notes = "用户修改自己的手机号码")
    //@PostMapping("/change-phone")
    //@Override
    //public JsonVO<String> changePhone(@RequestBody @Validated ModifyPhoneDTO modifyPhoneDTO) {
    //    return userService.modifyPhone(modifyPhoneDTO);
    //}

    /**
     * 修改邮箱
     * @param emailDTO 修改后的邮箱
     * @return
     */
    @ApiOperation("修改邮箱")
    @PostMapping("/change-mail")
//    @ApiImplicitParam(name = "email",value = "修改后的邮箱，例如：admin@01xq.com",required = true)
    @Override
    public JsonVO modifyMail(@RequestBody EmailDTO emailDTO) {
        return JsonVO.success("修改成功");
    }

    /**
     * 获取短信验证码
     * @param getSmsCodeDTO 获取短信验证码数据传输对象
     * @return
     */
    @ApiOperation(value = "获取短信验证码")
    @GetMapping("/query-sms-code")
    @Override
    public JsonVO<String> getSmsCode(@Validated GetSmsCodeDTO getSmsCodeDTO) {
        System.out.println("调用第三方服务, 给手机发送验证码");
        return JsonVO.success("验证码已发送");
    }

    /**
     * 获取邮箱验证码
     * @param emailCodeQuery 获取邮箱验证码数据传输对象
     * @return 字符串提示消息
     */
    @ApiOperation(value = "获取邮箱验证码")
    @GetMapping("/query-email-code")
    @Override
    public JsonVO<String> getEmailCode(@Validated EmailCodeQuery emailCodeQuery) {
        System.out.println("调用第三方服务, 给邮箱发送验证码");
        return JsonVO.success("验证码已发送");
    }
}
