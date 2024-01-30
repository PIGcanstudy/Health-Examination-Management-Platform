package com.zeroone.star.project.dto.j3.dictdata;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * *作者：MSNzqs
 * *日期：2024/1/27 16:16
 * *文件描述：字典数据传输对象
 */

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("字典数据DTO")
public class DictDataDTO implements Serializable {
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
     * 删除标记 0不删除 1已删除
     */
    private Boolean delFlag;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 备注
     */
    private String description;

    /**
     * 对应字典编号
     */
    private Long dictId;

    /**
     * 排序号
     */
    private BigDecimal sortOrder;

    /**
     * 是否启用 0 启用 1 禁用
     */
    private Boolean status;

    /**
     * 数据名称
     */
    private String title;

    /**
     * 数据值
     */
    private String value;
}
