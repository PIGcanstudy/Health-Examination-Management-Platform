package com.zeroone.star.project.j2.dto;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：消息详情传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author camille
 * @version 1.0.0
 */
@Data
@ApiModel("消息传输对象")
public class MessageDTO {
    @ApiModelProperty(value = "Id",example = "1")
    private String id;

    @ApiModelProperty(value = "创建人Id",example = "1")
    private String createBy;

    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "修改人Id",example = "1")
    private String updateBy;

    @ApiModelProperty(value = "修改时间")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "删除标记 0 不删除 1 已删除",example = "0")
    private Integer delFlag;

    @ApiModelProperty(value = "标题",example = "标题")
    private String title;

    @ApiModelProperty(value = "内容",example = "内容")
    private String content;

    @ApiModelProperty(value = "是否发送给新人 0 否 1 是",example = "1")
    private Boolean createSend;

    @ApiModelProperty(value = "消息类型")
    private String type;

}
