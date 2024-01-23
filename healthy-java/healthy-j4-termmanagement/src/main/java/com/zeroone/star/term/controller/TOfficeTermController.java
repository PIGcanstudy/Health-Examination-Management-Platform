package com.zeroone.star.term.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;

import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;

import com.zeroone.star.project.j4.sales.TermApis;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.term.service.ITOfficeTermService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;


@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
public class TOfficeTermController implements TermApis {
    @Resource
    private ITOfficeTermService itOfficeTermService;

    @ApiOperation("获取术语列表")
    @GetMapping("query-term-list")
    @Override
    public JsonVO<PageDTO<TermDto>> queryTermListAll(@Validated TermQuery condition) {
        return JsonVO.success(itOfficeTermService.queryTermList(condition));
    }

    @ApiOperation("获取术语名称列表")
    @GetMapping("query-termname-list")
    @Override
    public JsonVO<PageDTO<TermDto>> queryTermnameList(@Validated TermNameQuery condition1) {
        return JsonVO.success(itOfficeTermService.queryTermnameList(condition1));

    }

    @ApiOperation("获取术语详情")
    @GetMapping("query-term-detail")
    @Override
    public JsonVO<TermDto> queryTermDetail(String id) {
        return JsonVO.success(itOfficeTermService.queryTermDetail(id));

    }





}


