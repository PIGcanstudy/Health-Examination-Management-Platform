package com.zeroone.star.departmanagement.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.departmanagement.common.ConvertUtil;
import com.zeroone.star.departmanagement.entity.SectionOfficeEntity;
import com.zeroone.star.departmanagement.mapper.GetSectionOfficeMapper;
import com.zeroone.star.departmanagement.service.SectionOfficeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class SectionOfficeEntityServiceImpl extends ServiceImpl<GetSectionOfficeMapper, SectionOfficeEntity> implements SectionOfficeService {
    @Autowired
    private GetSectionOfficeMapper getSectionOfficeMapper;

    /**
     * 获取科室管理列表（分页+条件）
     * @param query
     * @return GetSectionOfficeVO
     */
    @Override
    public PageDTO<GetSectionOfficeVO> listAllSectionOffice(GetSectionOfficeQuery query){
        Page<GetSectionOfficeQuery> page = Page.of(query.getPageIndex(), query.getPageSize());
        Page<GetSectionOfficeVO> secVO = getSectionOfficeMapper.selectAll(page, query);
        //将page对象转换为list对象
        List<GetSectionOfficeVO> records = secVO.getRecords();
        secVO.getRecords();
        return PageDTO.create(secVO);
    }

    /**
     * 获取科室管理名称列表
     * @param getSecNameDTO
     * @return GetSecNameVO
     */
    @Override
    public List<GetSecNameVO> listAllName(GetSecNameDTO getSecNameDTO) {
        LambdaQueryWrapper<SectionOfficeEntity> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.like(getSecNameDTO.getName()!=null, SectionOfficeEntity::getSectionName,getSecNameDTO.getName());
        List<SectionOfficeEntity> sectionOfficeEntities = baseMapper.selectList(queryWrapper);
        return ConvertUtil.sourceToTarget(sectionOfficeEntities, GetSecNameVO.class);

    }

    /**
     * 获取详细列表
     * @param getSectionOfficetDTO
     * @return getSectionOfficetVO
     */

    @Override
    public List<GetSectionOfficeVO> getAllSectionOffice(GetSectionOfficetDTO getSectionOfficetDTO) {
        LambdaQueryWrapper<SectionOfficeEntity> queryWrapper = new LambdaQueryWrapper<>();
        List<SectionOfficeEntity> sectionOfficeEntities = baseMapper.selectList(queryWrapper);
        return ConvertUtil.sourceToTarget(sectionOfficeEntities, GetSectionOfficeVO.class);
    }


}
