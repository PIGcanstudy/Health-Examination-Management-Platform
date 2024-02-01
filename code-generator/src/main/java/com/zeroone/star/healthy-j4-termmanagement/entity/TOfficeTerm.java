package com.zeroone.star.healthy-j4-termmanagement.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 科室术语表
 * </p>
 *
 * @author xiangjun
 * @since 2024-01-30
 */
@Getter
@Setter
@TableName("t_office_term")
public class TOfficeTerm implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String id;

    /**
     * 科室Id
     */
    private String officeId;

    /**
     * 危害因素text
     */
    private String hazardFactorsText;

    /**
     * 体检类型
     */
    private String inspectType;

    /**
     * 危害因素
     */
    private String hazardFactors;

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
    private Float orderNum;

    /**
     * 是否删除(0-未删除，1-已删除)
     */
    private Integer delFlag;

    /**
     * 创建人
     */
    private String createId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    private String updateId;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 删除人
     */
    private String deleteId;

    /**
     * 删除时间
     */
    private LocalDateTime deleteTime;

    /**
     * 在岗状态编码
     */
    private String workStateCode;

    /**
     * 在岗状态
     */
    private String workStateText;


}
