package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.direct.DirectSourceApis;
import com.zeroone.star.project.j3.dto.dictdata.AddDictDataDTO;
import com.zeroone.star.project.j3.dto.dictdata.UpdateDictDataDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/j3-dictdata")
@Api("字典数据")
public class DictDataController implements DirectSourceApis {
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
}
