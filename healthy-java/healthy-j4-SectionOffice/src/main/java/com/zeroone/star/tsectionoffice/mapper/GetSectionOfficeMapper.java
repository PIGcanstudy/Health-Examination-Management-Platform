package com.zeroone.star.tsectionoffice.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;
@Mapper
public interface GetSectionOfficeMapper  {
    Page<GetSectionOfficeVO> selectAll(Page<GetSectionOfficeQuery> page, @Param("query") GetSectionOfficeQuery query);


}
