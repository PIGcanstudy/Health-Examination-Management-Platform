package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import java.util.Date;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Data
@ApiModel(value = "列表")
public class TermDto {

    @ApiModelProperty(value = "科室名称")
    private String name;

    @ApiModelProperty(value = "体检类型")
    private String medicalType;

    @ApiModelProperty(value = "属于类型")
    private String termType;

    @ApiModelProperty(value = "危害因素")
    private String hazardFactor;

    @ApiModelProperty(value = "在岗状态")
    private String jobStatus;

    @ApiModelProperty(value = "状态")
    private String status;

    @ApiModelProperty(value = "术语内容")
    private String termContent;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;

    @ApiModelProperty(value = "操作")
    private String operation;
}
