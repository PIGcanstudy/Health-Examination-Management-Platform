package com.zeroone.star.project.j3.dto.dictdata;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("新增字典数据DTO")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class AddDictDataDTO {
    @ApiModelProperty(value = "名称",example = "健康体检")
    private String title;
    @ApiModelProperty(value = "数据值",example = "健康体检")
    private String value;
    @ApiModelProperty(value = "备注",example = "A")
    private String description;
    @ApiModelProperty(value = "排序值",example = "1.00")
    private  java.math.BigDecimal sort_order;
    @ApiModelProperty(value = "是否启用",example = "0")
    private Integer status ;
}
