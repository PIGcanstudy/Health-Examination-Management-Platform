package com.zeroone.star.sysmanager.controller;



import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dictdata.DictDataDTO;
import com.zeroone.star.project.j3.dictory.DirectSourceApis;
import com.zeroone.star.project.dto.j3.dictdata.AddDictDataDTO;
import com.zeroone.star.project.dto.j3.dictdata.UpdateDictDataDTO;
import com.zeroone.star.project.query.j3.DictData.DictDataQuery;
import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.ITDictDataService;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * 字典数据controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:04
 **/
@RestController
@RequestMapping("/j3-directSource")
@Api("字典数据")
public class DirectSourceController implements DirectSourceApis {

    @Resource
    ITDictDataService itDictDataService;
    @ApiOperation("新增字典数据")
    @PostMapping("/addDictData")
    @Override
    public JsonVO<PageDTO<UpdateDictDataDTO>> UpdateDictData() {
        return null;
    }

    @ApiOperation("修改字典数据")
    @PostMapping ("/updateDictData")
    @Override
    public JsonVO<PageDTO<AddDictDataDTO>> AddDictData() {
        return null;
    }

    @ApiOperation("查询字典数据名称列表")
    @GetMapping("/queryDataTitle")
    @Override
    public JsonVO<List<String>> queryDictDataTitle() {
        return null;
    }
    @ApiOperation("查询字典数据列表")
    @PostMapping("/queryDictDataByCondition")
    @Override
    public JsonVO<PageDTO<DictDataDTO>> queryDictDataByCondition(DictDataQuery condition) {
        return null;
    }

    @ApiOperation("根据id批量删除数据字典")
    @PostMapping("/deleteByIds")
    @Override
    public JsonVO<Boolean> deleteByIds(@RequestParam String[] ids) {
        return null;
    }

    @ApiOperation("获取工种名称列表")
    @GetMapping("/queryByWordType")
    @Override
    public JsonVO<List<WordTypeListQuery>> queryByWordType(WordTypeListQuery wordTypeListQuery) {
        return null;
    }
}
