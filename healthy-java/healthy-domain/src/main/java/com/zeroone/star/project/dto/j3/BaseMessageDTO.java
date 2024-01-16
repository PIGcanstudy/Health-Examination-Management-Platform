package com.zeroone.star.project.dto.j3;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * 发送消息/消息查看公共类
 *
 * @author ZhangJF
 * @date 2024/01/15 16:53
 **/
@ApiModel("消息基本数据对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class BaseMessageDTO {
    @ApiModelProperty(value = "消息id",required = true)
    private Long id;
    @ApiModelProperty(value = "创建人",required = true)
    private String createBy;
    @ApiModelProperty(value = "创建时间",required = true)
    private Date createTime;
    @ApiModelProperty(value = "修改人",required = true)
    private String updateBy;
    @ApiModelProperty(value = "修改时间",required = true)
    private Date updateTime;
    @ApiModelProperty(value = "逻辑删除字段",example = "0",required = true)
    private Integer delFlag;
}
