package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Email;

@Data
@ApiModel("修改邮箱传输的数据")
public class EmailDTO {
    @Email
    @ApiModelProperty(value = "邮箱", required = true, example = "admin@01xq.com")
    private String email;
}
