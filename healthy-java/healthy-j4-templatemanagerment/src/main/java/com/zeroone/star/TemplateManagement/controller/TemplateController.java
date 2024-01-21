package com.zeroone.star.TemplateManagement.controller;

import com.zeroone.star.project.j4.dto.TemplateDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import com.zeroone.star.project.j4.template.TemplateApis;
@RestController
@Api(tags = "模板管理接口")
@RequestMapping("/template")
public class TemplateController implements TemplateApis {

    @PostMapping("add-template")
    @ApiOperation("新增模板")
    @Override
    public JsonVO<ResultStatus> addTemplate(@RequestBody TemplateDto templateDto) {
        return null;
    }

    @ApiOperation("获取模板详情")
    @GetMapping("query-term-detail/{termId}")
    @Override
    public JsonVO<TemplateDto> queryTermDetail(@PathVariable("templateId") Long termId) {
        return JsonVO.success(null);
    }
}
