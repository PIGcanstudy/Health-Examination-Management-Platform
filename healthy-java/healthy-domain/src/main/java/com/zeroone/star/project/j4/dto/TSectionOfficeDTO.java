package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @BelongsProject: healthy-java
 * @BelongsPackage: com.zeroone.star.project.j4.dto
 * @Author: ayuan
 * @CreateTime: 2024-01-16
 * @Description:
 */
@Data
@ApiModel("科室数据")
public class TSectionOfficeDTO {
    @ApiModelProperty(value = "唯一编号", example = "173")
    private String id;
    @ApiModelProperty(value = "科室编码", example = "013")
    private String sectionCode;
    @ApiModelProperty(value = "科室名称", example = "问诊科")
    private String sectionName;
    @ApiModelProperty(value = "科室简拼", example = "wzk")
    private String sectionAlphbet;
    @ApiModelProperty(value = "排序", example = "0")
    private Float orderNum;
    @ApiModelProperty(value = "联系人", example = "abc")
    private String contact;
    @ApiModelProperty(value = "联系人电话", example = "18931599999")
    private String contactMobile;
    @ApiModelProperty(value = "检查类型", example = "职业体检,健康体检,从业体检")
    private String checkType;




}
