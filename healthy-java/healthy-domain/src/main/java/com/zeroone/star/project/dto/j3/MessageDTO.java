package com.zeroone.star.project.dto.j3;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 消息基本类型
 *
 * @author ZhangJF
 * @date 2024/01/15 17:24
 **/
@Api("消息基本类型")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MessageDTO extends BaseMessageDTO {
    @ApiModelProperty(value = "标题",example = "Title")
    private String title;
    @ApiModelProperty(value = "内容",example = "Content")
    private String content;
    @ApiModelProperty(value = "是否发送新人",example = "0",required = true)
    private Integer createSend;
    @ApiModelProperty(value = "消息类型",example = "Type")
    private String type;
}
