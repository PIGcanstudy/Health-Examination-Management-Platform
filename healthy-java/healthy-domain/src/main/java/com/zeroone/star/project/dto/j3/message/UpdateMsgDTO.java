package com.zeroone.star.project.dto.j3.message;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.io.Serializable;

/**
 * @version 1.0
 * @Author 卢守征
 * @Date 2024/1/19 16:50
 * @注释
 */

@Data
@ApiModel("修改信息DTO")
public class UpdateMsgDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotBlank(message = "id不能为空")
    @ApiModelProperty(value = "唯一标识")
    private String id;

    @NotBlank(message = "目前用户id不能为空")
    @ApiModelProperty(value = "目前用户id")
    private String userID;

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
}
