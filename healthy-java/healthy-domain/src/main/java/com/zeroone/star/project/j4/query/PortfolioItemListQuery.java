package com.zeroone.star.project.j4.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.validation.annotation.Validated;

/**
 * @Description: 获取项目列表 (条件+分页)
 * @Author: Laputa
 * @CreateTime: 2024-01-20  11:56
 * @Version: 1.0
 */
@Validated
@Data
@ApiModel("获取项目列表 (条件+分页)")
public class PortfolioItemListQuery extends PageQuery {
    @ApiModelProperty(value = "资源类型（-1顶部菜单  0界面菜单 1操作按钮）", example = "0")
    private Integer type;

    @ApiModelProperty(value = "是否启用（0 启动 1禁用）", example = "0")
    private Integer status;
}
