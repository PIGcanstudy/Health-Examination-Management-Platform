package com.zeroone.star.sample.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.sample.entity.Sample;
import com.zeroone.star.sample.mapper.SampleMapper;
import com.zeroone.star.sample.service.ISampleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：Sample对应MapStruct映射接口
 * </p>
 *
 * @author TripleG
 * @since 2024-01-15
 */
@Mapper(componentModel = "spring")
interface MsSampleMapper {
    /**
     * 将SampleDO 转换成 SampleDTO
     * @param sample 待转换的DO
     * @return 转换结果DTO
     */
    SampleDTO sampleToSampleDTO(Sample sample);
}

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author TripleG
 * @since 2024-01-15
 */
@Service
public class SampleServiceImpl extends ServiceImpl<SampleMapper, Sample> implements ISampleService {
    @Resource
    MsSampleMapper msSampleMapper;
    @Override
    public PageDTO<SampleDTO> listPage(SampleQuery query) {
        // 构建分页条件对象
        Page<Sample> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<Sample> wrapper = new QueryWrapper<>();
        wrapper.like("name", query.getName());
        // 执行查询
        Page<Sample> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, src -> msSampleMapper.sampleToSampleDTO(src));
    }

    @Override
    public SampleDTO getById(int id) {
        Sample sample = baseMapper.selectById(id);
        if (sample != null) {
            return msSampleMapper.sampleToSampleDTO(sample);
        }
        return null;
    }
}
