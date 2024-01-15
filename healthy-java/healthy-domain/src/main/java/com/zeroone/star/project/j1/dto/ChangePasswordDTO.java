package com.zeroone.star.project.j1.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("修改密码数据对象")
public class ChangePasswordDTO {
    @NotBlank(message = "密码不能为空")
    @ApiModelProperty(value = "旧密码", example = "123456",required = true)
    private String password;

    @NotBlank(message = "密码不能为空")
    @ApiModelProperty(value = "新密码", example = "12345678",required = true)
    private String new_password;

    @NotBlank(message = "用户id不能为空")
    @ApiModelProperty(value = "用户id", example = "682265633886208",required = true)
    private String id;


    @NotBlank(message = "密码强度不能为空")
    @ApiModelProperty(value = "密码强度", example = "弱",required = true)
    private String pass_strength;


}
