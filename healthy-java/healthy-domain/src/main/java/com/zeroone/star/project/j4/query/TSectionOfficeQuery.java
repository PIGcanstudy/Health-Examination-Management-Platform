package com.zeroone.star.project.j4.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @BelongsProject: healthy-java
 * @BelongsPackage: com.zeroone.star.project.j4.query
 * @Author: ayuan
 * @CreateTime: 2024-01-16
 * @Description:
 */
@Data
@ApiModel("科室查询")
public class TSectionOfficeQuery extends PageQuery {
    @ApiModelProperty(value = "科室编码", example = "013")
    private String sectionCode;
}
