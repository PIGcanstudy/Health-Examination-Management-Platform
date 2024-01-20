package com.zeroone.star.project.j1.vo.sysmanager.entiy;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.models.auth.In;
import lombok.Data;

@Data
@ApiModel("角色分配")
public class Role {
    @ApiModelProperty(value = "角色名称", example = "技术负责人")
    private String name;
}
