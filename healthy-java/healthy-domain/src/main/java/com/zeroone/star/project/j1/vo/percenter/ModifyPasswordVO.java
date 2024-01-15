package com.zeroone.star.project.j1.vo.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 *  修改密码视图对象
 */
@Data
@ApiModel(description = "用户修改密码信息")
public class ModifyPasswordVO {
    @ApiModelProperty(value = "用户ID")
    private Long userId;

    @ApiModelProperty(value = "原密码", required = true)
    private String oldPassword;

    @ApiModelProperty(value = "新密码", required = true)
    private String newPassword;

    @ApiModelProperty(value = "确认新密码", required = true)
    private String confirmPassword;
}

