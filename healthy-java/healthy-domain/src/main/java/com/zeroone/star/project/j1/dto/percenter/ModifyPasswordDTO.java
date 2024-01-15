package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 用户密码修改的数据传输对象
 */
@Data
@ApiModel(description = "用户修改密码信息")
public class ModifyPasswordDTO {
    @ApiModelProperty(value = "用户ID", required = true)
    private Long userId;

    @ApiModelProperty(value = "原密码", required = true)
    private String oldPassword;

    @ApiModelProperty(value = "新密码", required = true)
    private String newPassword;

}