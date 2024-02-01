package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dict.WordTypeListDTO;
import com.zeroone.star.project.j3.direct.DirectSourceApis;
import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.DictData;
import com.zeroone.star.sysmanager.service.ITDictDataService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * 字典数据controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:04
 **/
@RestController
@RequestMapping("/j3-directSource")
@Api(tags = "字典数据")
public class DirectSourceController implements DirectSourceApis {

    @Resource
    ITDictDataService itDictDataService;

    @ApiOperation("根据id批量删除数据字典")
    @PostMapping("/deleteByIds")
    @Override
    public JsonVO<Boolean> deleteByIds(@RequestParam String[] ids) {
        for (String id : ids) { //这些id是t_dict_data里面的id
            //根据数据id先查询数据库，看是否存在数据
            DictData dictData=itDictDataService.getById(id);
            if(dictData == null){   //数据为空，失败逻辑
                return JsonVO.fail(Boolean.FALSE);
            }
            //否则的话执行删除
            itDictDataService.removeById(id);
        }
        //删除成功
        return JsonVO.success(Boolean.TRUE);
    }

    @ApiOperation("获取工种名称列表")
    @GetMapping("/queryByWordType")
    @Override
    public JsonVO<PageDTO<WordTypeListDTO>> queryByWordType(WordTypeListQuery wordTypeListQuery) {
        return JsonVO.success(itDictDataService.listPage(wordTypeListQuery));
    }

}
