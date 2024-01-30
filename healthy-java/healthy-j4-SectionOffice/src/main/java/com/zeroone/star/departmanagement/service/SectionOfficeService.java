package com.zeroone.star.departmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.departmanagement.entity.SectionOfficeEntity;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;

import java.util.List;


/**
 * (SectionOffice)表服务接口
 *
 * @author makejava
 * @since 2024-01-17 21:52:31
 */

public interface SectionOfficeService extends IService<SectionOfficeEntity> {


    /**
     * 分页查询符合条件数据
     * @param getSectionOfficeQuery
     * @return
     */
    PageDTO<GetSectionOfficeVO> listAllSectionOffice(GetSectionOfficeQuery getSectionOfficeQuery);

    /**
     * 获取名称列表
     * @param getSecNameDTO
     * @return
     */
    List<GetSecNameVO> listAllName(GetSecNameDTO getSecNameDTO);

    List<GetSectionOfficeVO> getAllSectionOffice(GetSectionOfficetDTO getSectionOfficetDTO);
}
