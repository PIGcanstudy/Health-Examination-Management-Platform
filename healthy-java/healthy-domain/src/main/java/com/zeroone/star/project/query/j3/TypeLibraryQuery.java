package com.zeroone.star.project.query.j3;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel("消息查询对象")
public class TypeLibraryQuery implements Serializable {

    @ApiModelProperty(value = "类型名称")
    private String typeName;

    @ApiModelProperty(value = "消息编码")
    private String typeCode;

    @ApiModelProperty(value = "起始日期")
    private String startDate;

    @ApiModelProperty(value = "结束日期")
    private String endDate;
}
