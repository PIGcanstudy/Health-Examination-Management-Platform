package com.zeroone.star.project.j4.dto;

import java.util.Date;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class TemplateDto {
    @ApiModelProperty(value = "主键id", example = "12345")
    private String id;

    @ApiModelProperty(value = "组合项目id", example = "proj_001")
    private String baseProjectId;

    @ApiModelProperty(value = "报告类型", example = "类型A")
    private String reportType;

    @ApiModelProperty(value = "类型", example = "类型B")
    private String type;

    @ApiModelProperty(value = "状态", example = "有效")
    private String status;

    @ApiModelProperty(value = "模板内容", example = "这是模板内容示例")
    private String content;

    @ApiModelProperty(value = "排序", example = "1")
    private Float orderNum;

    @ApiModelProperty(value = "模板内容文件名",example = "template_name.docx")
    private String contentName;

}
