package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description: 获取项目列表 (条件+分页）
 * @Author: Laputa
 * @CreateTime: 2024-01-20  12:10
 * @Version: 1.0
 */
@Data
@ApiModel("获取项目列表 (条件+分页")
public class PortfolioItemListDTO {
    @ApiModelProperty("主键")
    private String id;

    @ApiModelProperty("名称")
    private String name;
}
