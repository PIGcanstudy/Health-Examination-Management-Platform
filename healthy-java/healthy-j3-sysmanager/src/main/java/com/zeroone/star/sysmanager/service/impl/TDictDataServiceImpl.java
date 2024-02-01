package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dict.WordTypeListDTO;
import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.sysmanager.entity.DictData;
import com.zeroone.star.sysmanager.mapper.DictDataMapper;
import com.zeroone.star.sysmanager.service.ITDictDataService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsDictDataMapper{
    /**
     * 将DictData转为WordTypeListDTO
     * @param dictData
     * @return
     */
    WordTypeListDTO dictDataToWordTypeListDTO(DictData dictData);
}
/**
 * <p>
 * 字典数据 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TDictDataServiceImpl extends ServiceImpl<DictDataMapper, DictData> implements ITDictDataService {
    @Resource
    MsDictDataMapper msDictDataMapper;

    @Override
    public void removeById(String id) {
        baseMapper.deleteById(id);
    }


    @Override
    public DictData getById(String id) {
        DictData dictData = baseMapper.selectById(id);
        return dictData;
    }

    @Override
    public PageDTO<WordTypeListDTO> listPage(WordTypeListQuery wordTypeListQuery) {
        //构建分页条件对象
        Page<DictData> page= new Page<>(wordTypeListQuery.getPageIndex(),wordTypeListQuery.getPageSize());
        //构建查询条件
        QueryWrapper<DictData> wrapper = new QueryWrapper<>();
        wrapper.like("title", wordTypeListQuery.getTitle());
        //执行查询语句
        Page<DictData> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result,src -> msDictDataMapper.dictDataToWordTypeListDTO(src));
    }
}
