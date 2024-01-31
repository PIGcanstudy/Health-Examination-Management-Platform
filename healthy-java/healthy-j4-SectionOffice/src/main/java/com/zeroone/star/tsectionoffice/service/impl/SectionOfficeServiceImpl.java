package com.zeroone.star.tsectionoffice.service.impl;

import com.zeroone.star.tsectionoffice.mapper.GetSectionOfficeMapper;
import org.springframework.beans.factory.annotation.Autowired;

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
