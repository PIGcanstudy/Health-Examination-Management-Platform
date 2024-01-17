package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModelProperty;

import java.util.Date;

public class GetdepartmentVo extends PageVo{
    //编码
    @ApiModelProperty(value = "编码",example = "001",required = true)
    private String sectionCode;
    //科室名称
    @ApiModelProperty(value = "科室名称",example = "心电图",required = true)
    private String sectionName;
    //科室简拼
    @ApiModelProperty(value = "科室简拼",example = "XDT",required = true)
    private String sectionAlphbet;;
    //排序
    @ApiModelProperty(value = "排序",example = "1",required = true)
    private String orderNum;
    //联系人
    @ApiModelProperty(value = "联系人",example = "孙笑川",required = true)
    private String contact;
    //联系人电话
    @ApiModelProperty(value = "联系人电话",example = "114514",required = true)
    private String contactMobile;
    //检查类型
    @ApiModelProperty(value = "检查类型",example = "健康体检",required = true)
    private String checkType;

}
