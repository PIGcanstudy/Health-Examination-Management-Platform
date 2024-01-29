package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.project.j3.stopword.StopWordApis;
import com.zeroone.star.project.query.j3.StopWordQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.StopWord;
import com.zeroone.star.sysmanager.service.ITStopWordService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.ArrayList;
import java.util.List;

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

    @Resource
    private ITStopWordService stopWordService;
    @ApiOperation("分页查找禁用词")
    @GetMapping("/queryStopWord")
    @Override
    public JsonVO<PageDTO<StopWordDTO>> queryStopWord(StopWordQuery query) {
        return JsonVO.success(stopWordService.listpage(query));
    }

    @ApiOperation("添加禁用词")
    @PostMapping("/addStopWord")
    @Override
    public JsonVO<Boolean> addStopWord(StopWordDTO word) {
        if (word == null || word.getTitle() == null ||
                stopWordService.findByTitle(word.getTitle()) != null) {
            return JsonVO.fail(Boolean.FALSE);
        }
        StopWord stopWord = convertToStopWord(word); // 转换为StopWord类型
        stopWordService.save(stopWord);
        return JsonVO.success(Boolean.TRUE);
//        stopWordService.save(word);
//        return JsonVO.success(Boolean.TRUE);
    }
    // 添加一个转换方法，将StopWordDTO转换为StopWord
    private StopWord convertToStopWord(StopWordDTO dto) {
        StopWord stopWord = new StopWord();
        stopWord.setTitle(dto.getTitle());
        // 设置其他属性

        return stopWord;
    }

    @PutMapping("/updateWord")
    @ApiOperation("修改禁用词")
    @Override
    public JsonVO<Boolean> updateWord(UpdateWordDTO updateWord) {
        int count = stopWordService.updateWord(updateWord);
        if (count > 0) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @DeleteMapping("/deleteWordsByIds")
    @ApiOperation("批量删除禁用词")
    @Override
    public JsonVO<Boolean> deleteWordsByIds(@RequestParam List<String> ids) {
        boolean success = stopWordService.removeByIds(ids);
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }
}
