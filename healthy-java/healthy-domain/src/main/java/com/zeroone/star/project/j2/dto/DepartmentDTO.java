package com.zeroone.star.project.j2.dto;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@ApiModel("部门传输数据对象")
public class DepartmentDTO {
    @ApiModelProperty(value = "编号")
    private String id;

    @ApiModelProperty(value = "部门名称", example = "医疗部")
    private String title;

    @ApiModelProperty(value = "父部门编号", example = "2")
    private Long parentId;

    @ApiModelProperty(value = "排序号", example = "10")
    private BigDecimal sortOrder;

    /**
     * 逻辑删除标识 0 未删除 1 已删除
     */
    @ApiModelProperty(value = "是否删除", example = "1")
    private Integer delFlag;

    @ApiModelProperty(value = "部门是否禁用", example = "1")
    private Boolean status;

    @ApiModelProperty(value = "是否是父部门", example = "1")
    private Boolean isParent;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;
}
