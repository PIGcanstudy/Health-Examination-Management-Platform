package com.zeroone.star.term.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.term.entity.TOfficeTerm;
import com.zeroone.star.term.mapper.TOfficeTermMapper;
import com.zeroone.star.term.service.ITOfficeTermService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;


/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Mapper(componentModel = "spring")
interface MsTermMapper {
    /**
     * 将TermDO 转换成 TermDTO
     * @param tOfficeTerm 待转换的DO
     * @return 转换结果
     */
    TermDto termToTermDto(TOfficeTerm tOfficeTerm);
}
@Service
public class TOfficeTermServiceImpl extends ServiceImpl<TOfficeTermMapper, TOfficeTerm> implements ITOfficeTermService {
    @Resource
    MsTermMapper msTermMapper;
    @Override
    public PageDTO<TermDto> queryTermList(TermQuery query) {
        // 构建分页条件对象
        //表示要查询的分页条件
        Page<TOfficeTerm> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        //用于构建查询条件。
        QueryWrapper<TOfficeTerm> wrapper = new QueryWrapper<>();
        wrapper.like("inspect_type", query.getInspect_type());
        wrapper.like("type", query.getType());
        wrapper.like("hazard_factors", query.getHazard_factors());
        wrapper.like("work_state_text", query.getWork_state_text());
        wrapper.like("content", query.getContent());
        wrapper.like("create_time", query.getCreate_time());
        // 执行查询
        Page<TOfficeTerm> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, src -> msTermMapper.termToTermDto(src));
    }

    @Override
    public PageDTO<TermDto> queryTermnameList(TermNameQuery nameQuery) {
        Page<TOfficeTerm> page1 = new Page<>(nameQuery.getPageIndex(), nameQuery.getPageSize());
        // 构建查询条件
        //用于构建查询条件。
        QueryWrapper<TOfficeTerm> wrapper1 = new QueryWrapper<>();
        wrapper1.like("officeName", nameQuery.getOfficeName());
        wrapper1.like("inspect_type", nameQuery.getInspect_type());
        wrapper1.like("type", nameQuery.getType());
        wrapper1.like("hazard_factors", nameQuery.getHazard_factors());
        wrapper1.like("work_state_text", nameQuery.getWork_state_text());
        wrapper1.like("content", nameQuery.getContent());
        wrapper1.like("create_time", nameQuery.getCreate_time());
        // 执行查询
        Page<TOfficeTerm> result = baseMapper.selectPage(page1, wrapper1);
        return PageDTO.create(result, src -> msTermMapper.termToTermDto(src));

    }


    @Override
    public TermDto queryTermDetail(String id) {
        TOfficeTerm tOfficeTerm=baseMapper.selectById(id);
        if (tOfficeTerm != null) {
            return msTermMapper.termToTermDto(tOfficeTerm);
        }
        return null;
    }
}
