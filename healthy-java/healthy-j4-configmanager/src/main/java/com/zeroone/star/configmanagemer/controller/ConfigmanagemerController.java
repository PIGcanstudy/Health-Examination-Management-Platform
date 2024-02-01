package com.zeroone.star.configmanagemer.controller;

import com.zeroone.star.configmanagemer.service.ITSectionOfficeService;
import com.zeroone.star.project.j4.configmanagemer.ConfigmanagemerAPI;
import com.zeroone.star.project.j4.vo.SectionNameListVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * @author: jiemo
 * @description: 组合项目controller
 */
@RestController
@RequestMapping("configmanagemer")
@Api(tags = "配置管理接口")
public class ConfigmanagemerController implements ConfigmanagemerAPI {
    @Resource
    private ITSectionOfficeService itSectionOfficeService;

    @ApiOperation(value = "获取科室名称" )
    @GetMapping("query-secion-name-list")
    @Override
    public JsonVO<List<SectionNameListVO>> querySectionName() {
        return JsonVO.success(itSectionOfficeService.listSectionName());
    }
}
