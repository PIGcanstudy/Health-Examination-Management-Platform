package com.zeroone.star.project.j4.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Data
@ApiModel(value = "术语查询参数")
public class TermQuery extends PageQuery {

    @ApiModelProperty(value = "体检类型", example = "女性健康体检")
    private String medicalType;

    @ApiModelProperty(value = "术语类型", example = "症状")
    private String termType;

    @ApiModelProperty(value = "危害因素", example = "？？")
    private String hazardFactor;

    @ApiModelProperty(value = "在岗状态", example = "在职")
    private String jobStatus;

    @ApiModelProperty(value = "术语内容", example = "头痛。。。。")
    private String termContent;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;


}
