package com.zeroone.star.term.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;

import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;

import com.zeroone.star.project.j4.sales.TermApis;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.term.entity.TOfficeTerm;
import com.zeroone.star.term.service.ITOfficeTermService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;


@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
public class TOfficeTermController implements TermApis {
    @Resource
    private ITOfficeTermService itOfficeTermService;

//    /**
//     * 根据条件查询分类数据
//     * @param tOfficeTerm
//     * @return
//     */
//    @GetMapping("/list")
//    public JsonVO<List<TOfficeTerm>> list(TOfficeTerm tOfficeTerm) {
//        LambdaQueryWrapper<TOfficeTerm> queryWrapper = new LambdaQueryWrapper<>();
//        queryWrapper.eq(tOfficeTerm.getInspect_type() != null,TOfficeTerm::getInspect_type, tOfficeTerm.getInspect_type());
//        queryWrapper.eq(tOfficeTerm.getType()!=null, TOfficeTerm::getType,tOfficeTerm.getType());
//        queryWrapper.eq(tOfficeTerm.getHazard_factors()!=null,TOfficeTerm::getHazard_factors,tOfficeTerm.getHazard_factors());
//        queryWrapper.eq(tOfficeTerm.getStatus()!=null,TOfficeTerm::getStatus,tOfficeTerm.getStatus());
//
//        List<TOfficeTerm> list = itOfficeTermService.list(queryWrapper);
//        return JsonVO.success(list);
//    }


    @ApiOperation("获取术语列表")
    @GetMapping("query-term-list")
    @Override
    public JsonVO<PageDTO<TermDto>> queryTermListAll( @Validated TermQuery condition) {
        return JsonVO.success(itOfficeTermService.queryTermList(condition));
    }

    @ApiOperation("获取术语名称列表")
    @GetMapping("query-termname-list")
    @Override
    public JsonVO<PageDTO<TermDto>> queryTermnameList( @Validated TermNameQuery condition1) {
        return JsonVO.success(itOfficeTermService.queryTermnameList(condition1));

    }

    @ApiOperation("获取术语详情")
    @GetMapping("/query-term-detail/{id}")
    @Override
    public JsonVO<TermDto> queryTermDetail(@PathVariable String id) {
        return JsonVO.success(itOfficeTermService.queryTermDetail(id));

    }





}


