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
        //用于构建查询条件。在这个例子中，查询条件是根据termContent模糊匹配。
        QueryWrapper<TOfficeTerm> wrapper = new QueryWrapper<>();
        wrapper.like("体检类型", query.getInspectType());
        wrapper.like("术语类型", query.getType());
        wrapper.like("危害因素", query.getHazardFactors());
        wrapper.like("在岗状态", query.getWorkStateText());
        wrapper.like("术语内容", query.getContent());
        wrapper.like("创建时间", query.getCreateTime());
        // 执行查询
        Page<TOfficeTerm> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, src -> msTermMapper.termToTermDto(src));
    }

    @Override
    public PageDTO<TermDto> queryTermnameList(TermNameQuery nameQuery) {
        Page<TOfficeTerm> page1 = new Page<>(nameQuery.getPageIndex(), nameQuery.getPageSize());
        // 构建查询条件
        //用于构建查询条件。在这个例子中，查询条件是根据termContent模糊匹配。
        QueryWrapper<TOfficeTerm> wrapper1 = new QueryWrapper<>();
        wrapper1.like("体检类型", nameQuery.getInspectType());
        wrapper1.like("术语类型", nameQuery.getType());
        wrapper1.like("危害因素", nameQuery.getHazardFactors());
        wrapper1.like("在岗状态", nameQuery.getWorkStateText());
        wrapper1.like("术语内容", nameQuery.getContent());
        wrapper1.like("创建时间", nameQuery.getCreateTime());
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
