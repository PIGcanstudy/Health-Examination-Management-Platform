package com.zeroone.star.termmanagement.controller;



import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.j4.sales.TermApis;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.termmanagement.service.TermService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;

import javax.annotation.Resource;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
public class TermController implements TermApis {
    @Resource
    private TermService termService;

    @ApiOperation("获取术语列表")
    @GetMapping("query-term-list")
    @Override
    public JsonVO<PageDTO<TermDto>> queryTermList(TermQuery query) {
        PageDTO<TermDto> page = termService.queryTermList(query);
        return JsonVO.success(page);
    }

    @ApiOperation("获取术语名称列表")
    @GetMapping("query-termname-list")
    @Override
    public JsonVO<PageDTO<TermDto>> queryTermnameList(TermQuery query) {
        PageDTO<TermDto> page = termService.queryTermList(query);
        return JsonVO.success(page);
    }

    @ApiOperation("获取术语详情")
    @GetMapping("query-term-detail/{termId}")
    @Override
    public JsonVO<TermDto> queryTermDetail(@PathVariable("termId") Long termId) {
        TermDto termDetail = termService.queryTermDetail(termId);
        return JsonVO.success(termDetail);
    }
}
