package com.zeroone.star.project.query.j3.message;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * @version 1.0
 * @Author 卢守征
 * @Date 2024/1/19 16:11
 * @注释 消息查询对象
 */
@Data
@ApiModel("消息查询")
public class MsgListQuery extends PageQuery implements Serializable {

    // 序列化ID
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "消息标题", example = "msn重聚")
    private String msgTitle;

    @ApiModelProperty(value = "消息内容", example = "xxxxx")
    private String msgContent;

    @ApiModelProperty(value = "消息类型", example = "图片消息")
    private String msgType;

    @ApiModelProperty(value = "起始日期", example = "2023-01-01")
    private String startDate;

    @ApiModelProperty(value = "结束日期", example = "2023-01-18")
    private String endDate;
}
