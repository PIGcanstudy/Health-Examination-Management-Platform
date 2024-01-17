package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel(value = "获取短信验证码", description = "获取短信验证码数据传输对象")
public class GetSmsCodeDTO {
    @ApiModelProperty(value = "新手机号", required = true)
    private String newPhone;

    @ApiModelProperty(value = "验证码", required = true)
    private String verificationCode;
}
