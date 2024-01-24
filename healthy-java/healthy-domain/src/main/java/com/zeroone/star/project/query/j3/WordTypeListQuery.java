package com.zeroone.star.project.query.j3;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import java.io.Serializable;

/**
 * @author: chenxiaxin
 * @date: 2024/1/18
 **/
@Data
@ApiModel("获取工作名称列表请求体")
public class WordTypeListQuery implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "")
    private String name;

    @ApiModelProperty(value = "数据名称")
    private String title;

    @ApiModelProperty(value = "是否启用 0 启用 1 禁用")
    private int status;

    @Min(value = 1, message = "页码最小值为1")
    @ApiModelProperty(value = "查询页码", example = "1")
    private long pageNumber;

    @Min(value = 1, message = "条数最小值为1")
    @ApiModelProperty(value = "查询条数", example = "10")
    private long pageSize;

    @ApiModelProperty(value = "根据xx分类")
    private String sort;

    @ApiModelProperty(value = "排序规则",example = "asc")
    private String order;

    @ApiModelProperty(value = "字典id")
    private String dictld;



}
