package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.j3.stopword.StopWordApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;

/**
 * 禁用词
 *
 * @author ZhangJF
 * @date 2024/01/23 19:41
 **/
@RestController
@RequestMapping("/j3-stopWord")
@Api("禁用词管理")
public class StopWordController implements StopWordApis {

    @ApiOperation("分页查找禁用词")
    @GetMapping("/queryStopWord")
    @Override
    public JsonVO<PageDTO<StopWordDTO>> queryStopWord(PageDTO<StopWordDTO> query) {
        return null;
    }

    @ApiOperation("添加禁用词")
    @PostMapping("/addStopWord")
    @Override
    public JsonVO<String> addStopWord(String title) {
        return null;
    }

    @PutMapping("/updateWord")
    @ApiOperation("修改禁用词")
    @Override
    public JsonVO<StopWordDTO> updateWord(String title) {

        return null;
    }

    @DeleteMapping("/deleteWordsByIds")
    @ApiOperation("批量删除禁用词")
    @Override
    public JsonVO<Boolean> deleteWordsByIds(ArrayList<String> ids) {
        return null;
    }
}
