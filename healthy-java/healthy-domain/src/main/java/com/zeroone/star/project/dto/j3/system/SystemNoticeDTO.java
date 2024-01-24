package com.zeroone.star.project.dto.j3.system;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

@Data
@ApiModel("获取系统公告的dto")
public class SystemNoticeDTO implements Serializable {
    @ApiModelProperty(value = "id", required = true, example = "100")
    private String id;
    @ApiModelProperty(value = "创建人")
    private String createBy;
    @ApiModelProperty(value = "创建时间")
    private Date createTime;
    @ApiModelProperty(value = "删除标记")
    private Integer delFlag;
    @ApiModelProperty(value = "修改人")
    private String updateBy;
    @ApiModelProperty(value = "修改时间")
    private Date updateTime;
    @ApiModelProperty(value = "设置值")
    private String value;
}
