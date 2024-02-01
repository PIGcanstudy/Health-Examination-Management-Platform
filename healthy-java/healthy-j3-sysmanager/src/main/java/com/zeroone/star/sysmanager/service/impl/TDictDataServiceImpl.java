package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dictdata.DictDataDTO;
import com.zeroone.star.project.query.j3.DictData.DictDataQuery;
import com.zeroone.star.sysmanager.entity.DictData;
import com.zeroone.star.sysmanager.mapper.DictDataMapper;
import com.zeroone.star.sysmanager.service.ITDictDataService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * DictData对应MapperStruct映射接口
 */
@Mapper(componentModel = "spring")
interface MsDictDataMapper{

    /**
     * 将DO 转换成 DTO
     * @param dictData
     * @return
     */
    DictDataDTO DictDataToDictDataDto(DictData dictData);
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

    /**
     * dictData.stream(): 将dictData列表转换为一个流（Stream），这使得我们可以使用流式操作来处理数据。
     * .map(dictData::getName): 使用map操作将每个dictData对象映射为其name属性，即提取字典数据的名称。
     * .collect(Collectors.toList()): 将映射后的结果收集到一个新的List<String>中，并作为方法的最终返回值。
     * @return
     */
    @Override
    public List<String> getDictDataTitle() {
        //使用MyBatis-Plus提供的list方法从数据库中查询所有的字典数据实体，将结果存储在dictData列表中。
        List<DictData> dictData = list();
        // 使用Java 8 Stream API对字典数据实体列表进行处理
        // 将每个字典数据实体的名称提取出来，并构成一个新的列表
        return dictData.stream().map(DictData::getTitle).collect(Collectors.toList());
    }

    @Override
    public PageDTO<DictDataDTO> ListPage(DictDataQuery query) {
        //构建分页对象
        Page<DictData> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询对象
        QueryWrapper<DictData> wrapper = new QueryWrapper<>();
        wrapper.like("title", query.getTitle());
        wrapper.like("status", query.getStatus());
        //执行查询
        Page<DictData> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, src -> msDictDataMapper.DictDataToDictDataDto(src));
    }
}
