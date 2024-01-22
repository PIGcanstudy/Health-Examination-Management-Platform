package com.zeroone.star.project.j4.templateM;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.templateM.dto.TemplateMListDTO;
import com.zeroone.star.project.j4.templateM.query.TemplateMQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：TODO
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
public interface TemplateMApis {
    /**
     * 组合项目名称列表查询接口
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<TemplateMListDTO>> queryProjectNameList(TemplateMQuery query);

    /**
     * 模板列表查询接口
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<TemplateMListDTO>> queryTemplateList(TemplateMQuery query);
}
