package com.zeroone.star.project.dto.j3;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * @author ZhangJF
 * @date 2024/01/16 10:23
 **/
@Api("检索消息详情dto")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class SearchMessageDetailDTO extends PageDTO {
    @ApiModelProperty(value = "消息id",example = "1",required = true)
    private Long id;
    @ApiModelProperty(value = "用户id",example = "1",required = true)
    private Long userId;
}
