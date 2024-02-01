package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
@Data
@ApiModel(value = "获取科室管理名称列表")
public class GetSecNameDTO implements Serializable {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "科室id")
    private String id;
    @ApiModelProperty(value = "科室名称")
    private String name;
}
