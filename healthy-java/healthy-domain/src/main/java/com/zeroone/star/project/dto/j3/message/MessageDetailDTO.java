package com.zeroone.star.project.dto.j3.message;

import com.zeroone.star.project.query.PageQuery;
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
public class MessageDetailDTO extends PageQuery {
    /*pageNumber=1&pageSize=10&sort=createTime&order=desc&userId=&messageId=7&status=
请求方法:
GET*/
    @ApiModelProperty(value = "消息id",required = true)
    private String id;
    @NotBlank(message = "用户id不为空")
    @ApiModelProperty(value = "用户id")
    private Long userId;
    @NotBlank(message = "发送用户不为空")
    @ApiModelProperty(value = "发送用户")
    private String createBy;
    @NotBlank(message = "创建时间不为空")
    @ApiModelProperty(value = "创建时间")
    private Date createTime;
    @ApiModelProperty(value = "更新时间")
    private Date updateTime;
    @ApiModelProperty(value = "逻辑删除字段（状态）",example = "0",required = true)
    private Integer delFlag;
}
