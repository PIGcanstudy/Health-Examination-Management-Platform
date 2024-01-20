package com.zeroone.star.departmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.departmanagement.entity.SectionOffice;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;


/**
 * (SectionOffice)表服务接口
 *
 * @author makejava
 * @since 2024-01-17 21:52:31
 */
public interface SectionOfficeService extends IService<SectionOffice> {


    /**
     * 分页查询符合条件数据
     * @param getSectionOfficeQuery
     * @return
     */
     PageDTO<GetSectionOfficeVO> listAllSectionOffice(GetSectionOfficeQuery getSectionOfficeQuery);



}
