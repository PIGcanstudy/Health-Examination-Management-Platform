package com.zeroone.star.department.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 部门
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Getter
@Setter
@TableName("t_department")
public class TDepartment implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    private String id;

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
     * 逻辑删除标识 0 未删除 1 已删除
     */
    private Integer delFlag;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 父部门ID
     */
    private Long parentId;

    /**
     * 排序号
     */
    private BigDecimal sortOrder;

    /**
     * 状态 0 启用 1 禁用
     */
    private Boolean status;

    /**
     * 部门名称
     */
    private String title;

    /**
     * 是否父部门
     */
    private Boolean isParent;


}
