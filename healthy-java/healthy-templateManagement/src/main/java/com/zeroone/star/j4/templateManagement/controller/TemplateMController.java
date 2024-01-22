package com.zeroone.star.j4.templateManagement.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.templateM.TemplateMApis;
import com.zeroone.star.project.j4.templateM.dto.TemplateMListDTO;
import com.zeroone.star.project.j4.templateM.query.TemplateMQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：模板管理控制器
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@RestController
@RequestMapping("template-management")
@Api(tags = "模板管理接口")
public class TemplateMController implements TemplateMApis {
    @ApiOperation(value = "获取组合项目名称列表")
    @GetMapping("query-project-name-list")
    @Override
    public JsonVO<PageDTO<TemplateMListDTO>> queryProjectNameList(TemplateMQuery query) {
        return null;
    }

    @ApiOperation(value = "获取模板列表")
    @GetMapping("query-template-list")
    @Override
    public JsonVO<PageDTO<TemplateMListDTO>> queryTemplateList(TemplateMQuery query) {
        return null;
    }
}
