package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 用户手机号修改的数据传输对象
 */
@Data
@ApiModel(value = "ModifyPhoneDTO", description = "用户修改手机号的数据传输对象")
public class ModifyPhoneDTO {
    @ApiModelProperty(value = "用户ID", required = true)
    private Long userId;

    @ApiModelProperty(value = "用户密码", required = true)
    private String password;

    @ApiModelProperty(value = "新手机号", required = true)
    private String newPhone;

    @ApiModelProperty(value = "验证码", required = true)
    private String verificationCode;
}