package com.zeroone.star.project.j4.dto;



import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @author lj
 * 时间：2024.1.20
 * 功能：
 */
@Data
@ApiModel(value = "列表")
public class TermDto  {

    @ApiModelProperty(value = "科室名称",example = "肺功能")
    private String officeName;

    @ApiModelProperty(value = "体检类型",example = "职业体检")
    private String inspect_type;

    @ApiModelProperty(value = "术语类型",example = "诊断小结")
    private String type;

    @ApiModelProperty(value = "危害因素",example = "溴甲烷")
    private String hazard_factors;

    @ApiModelProperty(value = "在岗状态")
    private String work_state_text;

    @ApiModelProperty(value = "状态",example = "启用")
    private String status;

    @ApiModelProperty(value = "术语内容",example = "它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害")
    private String content;

    @ApiModelProperty(value = "创建时间",example = "2021-12-06 10:36:14")
    private Date create_time;

    @ApiModelProperty(value = "操作",example = "查看")
    private String operation;

}
