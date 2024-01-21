package com.zeroone.star.project.j4.templateM.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * <p>
 * 描述：模板管理查询对象 TemplateManagementQuery
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Data
@ApiModel(value = "模板管理查询对象")
public class TemplateMQuery extends PageQuery {
    /**
     * 查询类型
     */
    @ApiModelProperty(value = "查询类型", example = "1")    // 形成文档
    private Integer queryType;
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
    @ApiModelProperty(value = "项目名称", example = "")
    private String name;
    /**
     * 模板状态
     */
    @ApiModelProperty(value = "模板状态", example = "启用")
    private String status;
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2022-01-18 22:13:40")
    private Date createTime;
}
