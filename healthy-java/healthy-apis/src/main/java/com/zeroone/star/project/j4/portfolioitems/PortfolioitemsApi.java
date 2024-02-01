package com.zeroone.star.project.j4.portfolioitems;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.vo.BasePortfolioListVO;
import com.zeroone.star.project.j4.vo.ProjectNameListVO;
import com.zeroone.star.project.j4.vo.SectionNameListVO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author: jiemo
 * @description: 组合项目接口
 */

public interface PortfolioitemsApi {
    /**
     * 基础项目列表接口
     * @param query 查询条件
     * @return 基础项目列表
     */
    JsonVO<PageDTO<BasePortfolioListVO>> queryBasePortfolio(BasePortfolioListVO query);

    /**
     * 科室名称接口
     * @return 科室名称
     */
    JsonVO<SectionNameListVO> querySectionName();

    /**
     * 项目名称接口
     * @return 项目名称
     */
    JsonVO<ProjectNameListVO> queryProjectName();

}
