package com.zeroone.star.portfolioitems.service.impl;

import com.zeroone.star.portfolioitems.entity.TPortfolioProject;
import com.zeroone.star.portfolioitems.mapper.TPortfolioProjectMapper;
import com.zeroone.star.portfolioitems.service.ITPortfolioProjectService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemListDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 组合项目 服务实现类
 * </p>
 *
 * @author Laputa
 * @since 2024-01-24
 */
@Service
public class TPortfolioProjectServiceImpl extends ServiceImpl<TPortfolioProjectMapper, TPortfolioProject> implements ITPortfolioProjectService {
    @Autowired
    private TPortfolioProjectMapper  tPortfolioProjectMapper;


    @Override
    public PortfolioItemDTO getPortfolioItemById(String id) throws Exception {
        return null;
    }

    @Override
    public PageDTO<PortfolioItemListDTO> listPortfolioItems(PortfolioItemListDTO dto) throws Exception {
        return null;
    }
}
