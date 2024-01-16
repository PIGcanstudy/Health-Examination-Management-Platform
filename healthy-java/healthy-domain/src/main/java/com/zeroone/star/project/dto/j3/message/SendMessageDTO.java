package com.zeroone.star.project.dto.j3.message;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import io.github.classgraph.json.Id;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import java.io.Serializable;

@Data
@ApiModel("发送信息DTO")
public class SendMessageDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotBlank(message = "标题不能为空")
    @ApiModelProperty(value = "标题")
    private String title;

    @NotBlank(message = "内容不能为空")
    @ApiModelProperty(value = "内容")
    private String content;

    @NotBlank(message = "消息类型不能为空")
    @ApiModelProperty(value = "消息类型")
    private String type;

    @ApiModelProperty(value = "新创建账号也推送")
    private Boolean createSend;

    @Min(value = 0, message = "发送范围为0-1")
    @Max(value = 1, message = "发送范围为0-1")
    @TableField(exist = false)
    @ApiModelProperty(value = "发送范围")
    private Integer range;

    @TableField(exist = false)
    @ApiModelProperty(value = "发送指定用户id")
    private String[] userIds;

    @ApiModelProperty(value = "目前用户id")
    @TableField(exist = false)
    private Integer userID;

    @Id
    @TableId(type = IdType.AUTO)
    @ApiModelProperty(value = "唯一标识")
    private String id;
}
