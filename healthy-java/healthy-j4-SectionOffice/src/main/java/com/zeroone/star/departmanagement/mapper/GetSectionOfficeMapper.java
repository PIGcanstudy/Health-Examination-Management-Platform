package com.zeroone.star.departmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.departmanagement.entity.SectionOfficeEntity;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;
@Mapper
public interface GetSectionOfficeMapper extends BaseMapper<SectionOfficeEntity> {
    Page<GetSectionOfficeVO> selectAll(Page<GetSectionOfficeQuery> page, @Param("query") GetSectionOfficeQuery query);




}
