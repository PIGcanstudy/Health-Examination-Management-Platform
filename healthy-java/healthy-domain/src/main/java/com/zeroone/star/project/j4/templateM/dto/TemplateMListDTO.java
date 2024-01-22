package com.zeroone.star.project.j4.templateM.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * <p>
 * 描述：模板列表数据传输对象
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Data
@ApiModel("模板列表数据传输")
public class TemplateMListDTO {
    /**
     * 唯一编号
     */
    private String id;
    /**
     * 报告类型
     */
    @ApiModelProperty(value = "报告类型", example = "放射体检")
    private String reportType;
    /**
     * 模板类型
     */
    @ApiModelProperty(value = "模板类型", example = "引导单")
    private String type;
    /**
     * 项目名称
     */
    @ApiModelProperty(value = "组合项目名称", example = "")
    private String name;
    /**
     * 模板状态
     */
    @ApiModelProperty(value = "状态", example = "启用")
    private String status;
    /**
     * 模板内容文件名
     */
    @ApiModelProperty(value = "模板内容", example = "放射检查引导单.docx")
    private String contentName;
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2022-01-18 22:13:40")
    private Date createTime;
}
