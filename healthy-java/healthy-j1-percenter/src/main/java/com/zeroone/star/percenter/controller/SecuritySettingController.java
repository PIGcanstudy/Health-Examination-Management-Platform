package com.zeroone.star.percenter.controller;

import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.percenter.SecuritySettingApis;
import com.zeroone.star.project.j1.vo.percenter.ModifyPasswordVO;
import com.zeroone.star.project.j1.vo.percenter.ModifyPhoneVO;
import com.zeroone.star.project.j1.vo.sysmanager.ModifyMailVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/security-setting")
@Api(tags = "安全设置")
public class SecuritySettingController implements SecuritySettingApis {
    @ApiOperation(value = "修改密码", notes = "用户修改自己的密码")
    @PostMapping("/change-password")
    @Override
    public JsonVO<ModifyPasswordDTO> changePassword(@RequestBody ModifyPasswordVO modifyPasswordVO) {
        System.out.println("修改密码");
        return JsonVO.success(null);
    }
    @ApiOperation(value = "修改手机号", notes = "用户修改自己的手机号码")
    @PostMapping("/change-phone")
    @Override
    public JsonVO<ModifyPhoneDTO> changePhone(@RequestBody ModifyPhoneVO modifyPhoneVO) {
        System.out.println("修改手机号");
        return JsonVO.success(null);
    }

    @ApiOperation("修改邮箱")
    @GetMapping("/change-mail")
    @Override
    public JsonVO modifyMail(ModifyMailVO modifyMailVO) {
        return JsonVO.success(null);
    }
}
