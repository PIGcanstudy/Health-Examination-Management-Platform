package com.zeroone.star.cpp.controller;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.cpp.SampleApis;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.query.cpp.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.cpp.service.ISampleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author TripleG
 * @since 2024-01-15
 */
@RestController
@RequestMapping("cpp")
@Api(tags = "sample")
@Validated
public class SampleController implements SampleApis {
    @Resource
    ISampleService service;

    @GetMapping("query")
    @ApiOperation(value = "分页查询")
    @Override
    public JsonVO<PageDTO<SampleDTO>> queryAll(SampleQuery condition) {
        return service.get(BeanUtil.beanToMap(condition, false, true));
    }

    @PostMapping("add")
    @ApiOperation(value = "新增数据")
    @Override
    public JsonVO<Long> addData(SampleDTO dto) {
        return service.post(dto);
    }

    @PostMapping("modify")
    @ApiOperation(value = "修改数据")
    @Override
    public JsonVO<Long> modifyData(SampleDTO dto) {
        return service.put(dto);
    }

    @DeleteMapping("remove")
    @ApiOperation(value = "删除数据")
    @Override
    public JsonVO<Long> removeData(SampleDTO dto) {
        return service.delete((long) dto.getId());
    }
}

