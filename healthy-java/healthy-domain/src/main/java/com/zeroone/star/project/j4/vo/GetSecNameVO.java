package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
@Data
@ApiModel(value = "科室管理列表名字")
public class GetSecNameVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "科室名称")
    private String name;
}
