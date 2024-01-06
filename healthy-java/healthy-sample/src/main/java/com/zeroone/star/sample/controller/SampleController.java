package com.zeroone.star.sample.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.sample.SampleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sample.service.ISampleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import javax.validation.constraints.Min;

/**
 * <p>
 * 演示示例表 前端控制器
 * </p>
 * @author 阿伟
 * @since 2024-01-06
 */
@RestController
@RequestMapping("/sample")
@Api(tags = "sample")
@Validated
public class SampleController implements SampleApis {
    @Resource
    ISampleService service;

    @GetMapping("query-all")
    @ApiOperation(value = "分页查询")
    @Override
    public JsonVO<PageDTO<SampleDTO>> queryAll(@Validated SampleQuery condition) {
        return JsonVO.success(service.listPage(condition));
    }

    @Override
    public JsonVO<SampleDTO> queryById(int id) {
        return JsonVO.success(service.getById(id));
    }

    @GetMapping("query-one")
    @ApiOperation(value = "编号查询")
    public JsonVO<SampleDTO> queryByIdValidated(
            @Min(value = 1,message = "最小值必须为1")
            @RequestParam int id){
        return queryById(id);
    }
}

