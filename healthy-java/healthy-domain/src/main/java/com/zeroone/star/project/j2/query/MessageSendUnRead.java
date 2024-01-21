package com.zeroone.star.project.j2.query;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("消息详情查询对象")
public class MessageSendUnRead extends PageQuery {
    //状态
    @ApiModelProperty(value = "状态",example = "0")
    private Integer Status;
}
