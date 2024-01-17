package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModelProperty;

public class PageVo {
    @ApiModelProperty(value = "页数",example = "1",required = true)
    private Integer pagesize;
    @ApiModelProperty(value = "每页数量",example = "1",required = true)
    private Integer pagenumber;
}
