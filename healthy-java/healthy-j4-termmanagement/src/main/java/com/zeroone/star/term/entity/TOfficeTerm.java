package com.zeroone.star.term.entity;

import java.io.Serializable;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.Getter;

import java.time.LocalDateTime;

/**
 * <p>
 * 科室术语表
 * </p>
 *
 * @author lj
 * @since 2024-01-23
 */
@Data
@EqualsAndHashCode(callSuper = false)
public class TOfficeTerm implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    @TableId(value = "id", type = IdType.ASSIGN_UUID)
    private String id;

    /**
     * 科室Id
     */
    private String office_id;

    /**
     * 危害因素text
     */
    private String hazard_factors_text;

    /**
     * 体检类型
     */
    private String inspect_type;

    /**
     * 危害因素
     */
    private String hazard_factors;

    /**
     * 类型
     */
    private String type;

    /**
     * 状态(0-启用，1-停用)
     */
    private String status;

    /**
     * 术语内容
     */
    private String content;

    /**
     * 排序
     */
    private Float order_num;

    /**
     * 是否删除(0-未删除，1-已删除)
     */
    private Integer del_flag;

    /**
     * 创建人
     */
    private String create_id;

    /**
     * 创建时间
     */
    private LocalDateTime create_time;

    /**
     * 修改人
     */
    private String update_id;

    /**
     * 修改时间
     */
    private LocalDateTime update_time;

    /**
     * 删除人
     */
    private String delete_id;

    /**
     * 删除时间
     */
    private LocalDateTime delete_time;

    /**
     * 在岗状态编码
     */
    private String work_state_code;

    /**
     * 在岗状态
     */
    private String work_state_text;

    @ApiModelProperty("科室名称")
    @TableField(exist = false)
    private String officeName;

    @ApiModelProperty("类型名称")
    @TableField(exist = false)
    private String typeName;

//    @ApiModelProperty(value = "科室数据")
//    @TableField(exist = false)
//    private TSectionOffice officeData;
}