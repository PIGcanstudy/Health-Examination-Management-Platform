package com.zeroone.star.project.dto.j3.dictdata;

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
    @ApiModelProperty(value = "名称",example = "健康体检",required = true)
    private String title;
    @ApiModelProperty(value = "数据值",example = "健康体检",required = true)
    private String value;
    @ApiModelProperty(value = "备注",example = "A")
    private String description;
    @ApiModelProperty(value = "排序值",example = "1.00")
    private  java.math.BigDecimal sort_order;
    @ApiModelProperty(value = "是否启用",example = "0",required = true)
    private Boolean status ;
    @ApiModelProperty(value = "对应字典编号",example = "1534030617061232640",required = true)
    private Long dictId;
}
