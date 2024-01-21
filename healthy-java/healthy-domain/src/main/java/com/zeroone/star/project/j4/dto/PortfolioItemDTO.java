package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @Description: 组合项目的详情信息
 * @Author: Laputa
 * @CreateTime: 2024-01-20  11:36
 * @Version: 1.0
 */
@Data
@ApiModel("项目详情DTO")
public class PortfolioItemDTO {

    @ApiModelProperty("主键")
    private String id;

    @ApiModelProperty("名称")
    private String name;

    @ApiModelProperty("简称")
    private String shortName;

    @ApiModelProperty("排序")
    private float orderNum;

    @ApiModelProperty("父节点ID")
    private String parentId;

    @ApiModelProperty("科室名称")
    private String officeName;

    @ApiModelProperty("科室ID")
    private String officeId;

    @ApiModelProperty("原价（元）")
    private Integer marketPrice;

    @ApiModelProperty("销售价（元）")
    private Integer salePrice;

    @ApiModelProperty("成本价（元）")
    private Integer costPrice;

    @ApiModelProperty("适合人群")
    private String suitableRange;

    @ApiModelProperty("项目介绍")
    private String introduce;

    @ApiModelProperty("检查地址")
    private String address;

    @ApiModelProperty("备注")
    private String remark;

    @ApiModelProperty("是否删除(0-未删除，1-已删除)")
    private int delFlag;

    @ApiModelProperty("创建人")
    private String createId;

    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty("修改人")
    private String updateId;

    @ApiModelProperty("修改时间")
    private LocalDateTime updateTime;

    @ApiModelProperty("删除人")
    private String deleteId;

    @ApiModelProperty("删除时间")
    private LocalDateTime deleteTime;

    @ApiModelProperty("所属部门")
    private String departmentId;

    @ApiModelProperty("诊断模板")
    private String template;

    @ApiModelProperty("服务类型")
    private String serviceType;

    @ApiModelProperty("标本")
    private String specimen;

    @ApiModelProperty("诊台是否显示")
    private String diagnostic;

    @ApiModelProperty("是否为附件")
    private String isFile;

    @ApiModelProperty("获取影像结果的标识")
    private String url;

    @ApiModelProperty("lis标本")
    private String lisSpecimen;

    @ApiModelProperty("lis标本名字")
    private String lisSpecimenName;

    @ApiModelProperty("lis系统对应Id")
    private String lisId;

    @ApiModelProperty("lis系统对应编码")
    private String lisCode;

    @ApiModelProperty("部位名称")
    private String deptName;

    @ApiModelProperty("危险因素编码")
    private String hazardFactorCode;

}
