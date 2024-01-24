package com.zeroone.star.project.j4.portfolioitems;

import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @Description: TODO
 * @Author: Laputa
 * @CreateTime: 2024-01-24  16:57
 * @Version: 1.0
 */
public interface PortfolioProjectApi {
    /**
     * @description: 组合项目的详情信息
     * @author: Laputa
     * @date: 2024-01-24  16:57
     * @param:
     * @return:
     **/
    JsonVO<PortfolioItemDTO> getProtfolioItem(Integer id) throws Exception;

    /**
     * @description: 获取项目列表 (条件+分页）
     * @author: Laputa
     * @date:  2023-01-24  17:17
     * @param:
     * @return:
     **/
}
