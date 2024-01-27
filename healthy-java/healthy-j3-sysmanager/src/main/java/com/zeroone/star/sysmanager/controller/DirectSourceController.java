package com.zeroone.star.sysmanager.controller;



import com.zeroone.star.project.j3.direct.DirectSourceApis;
import com.zeroone.star.project.dto.j3.dictdata.AddDictDataDTO;
import com.zeroone.star.project.dto.j3.dictdata.ModifyDictData;
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
    public JsonVO<Boolean> AddDictData(AddDictDataDTO addDictDataDTO) {
        return null;
    }

    @ApiOperation("修改字典数据")
    @PostMapping ("/modifyDictData")
    @Override
    public JsonVO<Boolean> ModifyDictData(ModifyDictData modifyDictData) {
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
