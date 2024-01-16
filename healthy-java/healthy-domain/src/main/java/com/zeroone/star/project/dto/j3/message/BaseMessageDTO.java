package com.zeroone.star.project.dto.j3.message;

import io.github.classgraph.json.Id;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
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
    @Id
    @ApiModelProperty(value = "消息id",required = true)
    private Long id;
    @NotBlank(message = "创建人不能为空")
    @ApiModelProperty(value = "创建人",required = true)
    private String createBy;
    @NotBlank(message = "创建时间不为空")
    @ApiModelProperty(value = "创建时间",required = true)
    private Date createTime;
    @NotBlank(message = "修改人不为空")
    @ApiModelProperty(value = "修改人",required = true)
    private String updateBy;
    @ApiModelProperty(value = "修改时间",required = true)
    private Date updateTime;
    @ApiModelProperty(value = "逻辑删除字段",example = "0",required = true)
    private Integer delFlag;
}
