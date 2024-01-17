package com.zeroone.star.project.j1.vo.sysmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("修改用户邮箱")
public class ModifyMailVO {
    @ApiModelProperty(value = "修改邮箱",example = "xxx@xxx")
    private String email;
}
