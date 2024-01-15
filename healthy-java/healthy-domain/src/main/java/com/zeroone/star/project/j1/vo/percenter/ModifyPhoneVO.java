package com.zeroone.star.project.j1.vo.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 修改手机号视图对象
 */
@Data
@ApiModel(description = "用户修改手机号信息")
public class ModifyPhoneVO {
    @ApiModelProperty(value = "用户ID")
    private Long userId;

    @ApiModelProperty(value = "用户密码", required = true)
    private String password;

    @ApiModelProperty(value = "新手机号", required = true)
    private String newPhone;

    @ApiModelProperty(value = "验证码", required = true)
    private String verificationCode;
}