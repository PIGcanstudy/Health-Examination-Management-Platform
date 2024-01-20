package com.zeroone.star.termmanagement.service.Impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.termmanagement.dao.TermDao;
import com.zeroone.star.termmanagement.entity.Term;
import com.zeroone.star.termmanagement.service.TermService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import com.zeroone.star.project.dto.PageDTO;
@Mapper(componentModel = "spring")
interface MsTermMapper {
    /**
     * 将SampleDO 转换成 TermDTO
     * @param term 待转换的DO
     * @return 转换结果
     */
    TermDto termToTermDto(Term term);
}

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Service
public class TermServiceImpl extends ServiceImpl<TermDao, Term> implements TermService {
//    @Resource
//    private TermDao termDao;
    @Resource
    MsTermMapper msTermMapper;
    @Override
    public PageDTO<TermDto> queryTermList(TermQuery query) {
        // 构建分页条件对象
        Page<Term> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<Term> wrapper = new QueryWrapper<>();
        wrapper.like("name", query.getName());
        // 执行查询
        Page<Term> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, src -> msTermMapper.termToTermDto(src));

    }

    @Override
    public PageDTO<TermDto> queryTermnameList(TermQuery query) {
        return null;
    }

    @Override
    public TermDto queryTermDetail(long id) {
        return null;
    }


//    @Override
//    public TermDto getById(int id) {
//        Term term = baseMapper.selectById(id);
//        if (term != null) {
//            return msTermMapper.termToTermDto(term);
//        }
//        return null;
//    }

}
