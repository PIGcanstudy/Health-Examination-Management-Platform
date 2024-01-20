package com.zeroone.star.departmanagement.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.departmanagement.entity.SectionOffice;
import com.zeroone.star.departmanagement.mapper.GetSectionOfficeMapper;
import com.zeroone.star.departmanagement.service.SectionOfficeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

public class SectionOfficeServiceImpl  {
    @Autowired
    private GetSectionOfficeMapper getSectionOfficeMapper;




//    @Override
//    public PageDTO<GetSectionOfficeVO> listAllSectionOffice(GetSectionOfficeQuery query) {
//        Page<GetSectionOfficeQuery> page = Page.of(query.getPageIndex(), query.getPageSize());
//        List<GetSectionOfficeVO> getVo = getSectionOfficeMapper.selectAll(page, query);
//        List<GetSectionOfficeVO> records = getVo.get()
//    }


}
