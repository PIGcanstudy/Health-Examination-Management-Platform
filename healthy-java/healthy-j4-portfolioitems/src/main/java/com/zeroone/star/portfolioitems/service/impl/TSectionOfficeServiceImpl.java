package com.zeroone.star.portfolioitems.service.impl;

import com.zeroone.star.portfolioitems.entity.TSectionOffice;
import com.zeroone.star.portfolioitems.mapper.TSectionOfficeMapper;
import com.zeroone.star.portfolioitems.service.ITSectionOfficeService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.vo.SectionNameListVO;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 科室 服务实现类
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Service
public class TSectionOfficeServiceImpl extends ServiceImpl<TSectionOfficeMapper, TSectionOffice> implements ITSectionOfficeService {

    @Override
    public PageDTO<SectionNameListVO> listSectionName() {
        return null;
    }
}
