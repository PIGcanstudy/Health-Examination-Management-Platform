package com.zeroone.star.project.dto.j3.message;

import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import java.io.Serializable;

/**
 * @version 1.0
 * @Author 卢守征
 * @Date 2024/1/19 16:49
 * @注释
 */

@Data
@ApiModel("发送信息DTO")
public class SendMsgDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "唯一标识", example = "1")
    private String id;

    @NotBlank(message = "消息类型不能为空")
    @ApiModelProperty(value = "消息类型")
    private String type;

    @NotBlank(message = "标题不能为空")
    @ApiModelProperty(value = "标题")
    private String title;

    @NotBlank(message = "内容不能为空")
    @ApiModelProperty(value = "内容")
    private String content;

    @ApiModelProperty(value = "新创建账号也推送")
    private Boolean createSend;

    @Min(value = 0, message = "全体用户")
    @Max(value = 1, message = "指定用户")
    @TableField(exist = false)
    @ApiModelProperty(value = "发送范围")
    private Integer range;

    @TableField(exist = false)
    @ApiModelProperty(value = "发送指定用户id")
    private String[] userIds;
}