package com.zeroone.star.project.vo.j3.wordTypeList;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * @author: chenxiaxin
 * @date: 2024/1/18
 **/
@Data
@ApiModel("工种名称列表返回vo")
public class WordTypeListVo implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "主键id")
    @TableId(value = "id", type = IdType.AUTO)
    private String id;

    @ApiModelProperty(value = "创建人")
    private String createBy;


    @ApiModelProperty(value = "创建时间")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    @ApiModelProperty(value = "删除标记 0不删除 1已删除")
    private Boolean delFlag;

    @ApiModelProperty(value = "修改人")
    private String updateBy;

    @ApiModelProperty(value = "修改时间")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "备注")
    private String description;

    @ApiModelProperty(value = "对应字典编号")
    private Long dictId;

    @ApiModelProperty(value = "排序号")
    private BigDecimal sortOrder;


    @ApiModelProperty(value = "是否启用 0 启用 1 禁用")
    private Boolean status;

    @ApiModelProperty(value = "数据名称")
    private String title;

    @ApiModelProperty(value = "数据值")
    private String value;
}
