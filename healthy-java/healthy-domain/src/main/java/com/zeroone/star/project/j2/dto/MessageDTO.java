package com.zeroone.star.project.j2.dto;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("消息列表")
public class MessageDTO {
        //查询Id
        @ApiModelProperty(value = "查询Id",example = "1")
        private Integer id;
        //用户Id
        @ApiModelProperty(value = "发送用户Id",example = "1")
        private String UserId;
        //消息Id
        @ApiModelProperty(value = "消息Id",example = "1")
        private String MessageId;
        //创建人
        @ApiModelProperty(value = "创建人",example = "张三")
        private String CreateBy;
        //创建时间
        @ApiModelProperty(value = "创建时间",example = "2024-01-15")
        private String CreateTime;
        //状态
        @ApiModelProperty(value = "状态",example = "1")
        private Integer Status;
        //更新时间
        @ApiModelProperty(value = "查询Id",example = "1")
        private String UpdateTime;

    }

