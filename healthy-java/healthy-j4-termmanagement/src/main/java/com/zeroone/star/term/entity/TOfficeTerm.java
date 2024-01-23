package com.zeroone.star.term.entity;

import java.io.Serializable;

import com.baomidou.mybatisplus.annotation.*;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;
/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Data
@TableName("t_office_term")
@EqualsAndHashCode(callSuper = false)
@ApiModel(value="TOfficeTerm对象", description="科室术语表")
public class TOfficeTerm<TSectionOffice> implements Serializable {
    private static final long serialVersionUID = 1L;
//    private String name;
//     private String medicalType;
//     private String termType;
//     private String hazardFactor;
//     private String jobStatus;
//     private String status;
//     private String termContent;
//     private Date createTime;
//     private String operation;



    @ApiModelProperty(value = "主键" )
    @TableId(value = "id",type = IdType.ASSIGN_UUID)
    private String id;

    @TableField(value = "office_id")
    @ApiModelProperty(value = "科室Id")
    private String officeId;

    @TableField(value = "hazard_factors_text")
    @ApiModelProperty(value = "危害因素text")
    private String hazardFactorsText;

    @TableField(value = "inspect_type")
    @ApiModelProperty(value = "体检类型")
    private String inspectType;

    @TableField(value = "hazard_factors")
    @ApiModelProperty(value = "危害因素")
    private String hazardFactors;

    @ApiModelProperty(value = "类型")
    private String type;


    @ApiModelProperty(value = "状态")
    private String status;

    @ApiModelProperty(value = "术语内容")
    private String content;

    @TableField(value = "order_num")
    @ApiModelProperty(value = "排序")
    private Float orderNum;

    @TableField(value = "del_flag")
    @ApiModelProperty(value = "是否删除(0-未删除，1-已删除)")
    @TableLogic
    private Integer delFlag;

    @TableField(value = "create_id")
    @ApiModelProperty(value = "创建人")
    private String createId;

    @TableField(value = "create_time")
    @ApiModelProperty(value = "创建时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date createTime;

    @TableField(value = "update_id")
    @ApiModelProperty(value = "修改人")
    private String updateId;

    @TableField(value = "update_time")
    @ApiModelProperty(value = "修改时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date updateTime;

    @TableField(value = "delete_id")
    @ApiModelProperty(value = "删除人")
    private String deleteId;

    @TableField(value = "delete_time")
    @ApiModelProperty(value = "删除时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date deleteTime;

    @TableField(value = "work_state_code")
    @ApiModelProperty(value = "在岗状态编码")
    private String workStateCode;

    @TableField(value = "work_state_text")
    @ApiModelProperty(value = "在岗状态名称")
    private String workStateText;

    @ApiModelProperty("科室名称")
    @TableField(exist = false)
    private String officeName;

    @ApiModelProperty("类型名称")
    @TableField(exist = false)
    private String typeName;

    @ApiModelProperty(value = "科室数据")
    @TableField(exist = false)
    private TSectionOffice officeData;
}
