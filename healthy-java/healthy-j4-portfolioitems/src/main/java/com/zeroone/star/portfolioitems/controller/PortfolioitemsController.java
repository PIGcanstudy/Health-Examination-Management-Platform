package com.zeroone.star.portfolioitems.controller;

import com.zeroone.star.portfolioitems.service.ITBaseProjectService;
import com.zeroone.star.portfolioitems.service.impl.TBaseProjectServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.portfolioitems.PortfolioitemsApi;
import com.zeroone.star.project.j4.query.BasePortfolioListQuery;
import com.zeroone.star.project.j4.vo.BasePortfolioListVO;
import com.zeroone.star.project.j4.vo.ProjectNameListVO;
import com.zeroone.star.project.j4.vo.SectionNameListVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @author: jiemo
 * @description: 组合项目controller
 */
@RestController
@RequestMapping("portfolioitems")
@Api(tags = "组合项目接口")
public class PortfolioitemsController implements PortfolioitemsApi {
    @Resource
    private ITBaseProjectService itBaseProjectService;

    @ApiOperation(value = "分页获取基础项目列表" )
    @GetMapping("query-base-portfolio-list")
    @Override
    public JsonVO<PageDTO<BasePortfolioListVO>> queryBasePortfolio(BasePortfolioListQuery query) {
        return JsonVO.success(itBaseProjectService.ListBaseProject(query));
    }



    @ApiOperation(value = "获取科室名称" )
    @GetMapping("query-secion—name-list")
    @Override
    public JsonVO<SectionNameListVO> querySectionName() {
        return null;
    }

    @ApiOperation(value = "获取项目名称" )
    @GetMapping("query-project-name-list")
    @Override
    public JsonVO<ProjectNameListVO> queryProjectName() {
        return null;
    }
}
