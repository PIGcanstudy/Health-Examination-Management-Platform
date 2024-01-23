package com.zeroone.star.project.j4.dto;

import com.baomidou.mybatisplus.annotation.*;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.Min;
import java.util.Date;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Data
@TableName("t_office_term")
@ApiModel(value = "列表")
public class TermDto {

//    @ApiModelProperty(value = "科室名称",example = "肺功能")
//    private String name;

    @ApiModelProperty(value = "体检类型",example = "职业体检")
    private String medicalType;

    @ApiModelProperty(value = "术语类型",example = "诊断小结")
    private String termType;

    @ApiModelProperty(value = "危害因素",example = "溴甲烷")
    private String hazardFactor;

    @ApiModelProperty(value = "在岗状态")
    private String jobStatus;

//    @ApiModelProperty(value = "状态",example = "启用")
//    private String status;

    @ApiModelProperty(value = "术语内容",example = "它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害")
    private String termContent;

//    @ApiModelProperty(value = "创建时间",example = "2021-12-06 10:36:14")
//    private Date createTime;

    @ApiModelProperty(value = "操作",example = "查看")
    private String operation;



    @ApiModelProperty(value = "主键" )
    @TableId(value = "id",type = IdType.ASSIGN_UUID)
    private String id;

    @TableField(value = "office_id")
    @ApiModelProperty(value = "科室Id")
    private String officeId;


    @ApiModelProperty(value = "类型")
    private String type;

    @TableField(value = "inspect_type")
    @ApiModelProperty(value = "体检类型")
    private String inspectType;

    @TableField(value = "hazard_factors")
    @ApiModelProperty(value = "危害因素")
    private String hazardFactors;

    @TableField(value = "hazard_factors_text")
    @ApiModelProperty(value = "危害因素text")
    private String hazardFactorsText;

    @ApiModelProperty(value = "状态")
    private String status;

    @ApiModelProperty(value = "术语内容")
    private String content;

    @TableField(value = "order_num")
    @ApiModelProperty(value = "排序")
    private Float orderNum;

    @TableField(value = "work_state_code")
    @ApiModelProperty(value = "在岗状态编码")
    private String workStateCode;

    @TableField(value = "work_state_text")
    @ApiModelProperty(value = "在岗状态名称")
    private String workStateText;

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

    @TableField(value = "delect_id")
    @ApiModelProperty(value = "删除人")
    private String deleteId;

    @TableField(value = "delect_time")
    @ApiModelProperty(value = "删除时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date deleteTime;
}
