package com.zeroone.star.sysmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.project.query.j3.StopWordQuery;
import com.zeroone.star.sysmanager.entity.StopWord;
import com.zeroone.star.sysmanager.mapper.StopWordMapper;
import com.zeroone.star.sysmanager.service.ITStopWordService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestParam;

import javax.annotation.Resource;
import javax.management.Query;
import java.util.Optional;

/**
 * StopWord对应MapStruct映射接口
 */
@Mapper(componentModel = "spring")
interface  MsStopWordMapper{
    /**
    * 查询停用词
     * 将实体类DO转换为dto
     * @param stopWord 待转换DO
     * @return 转换结果
     */
    StopWordDTO StopWordToStopWordDTO(StopWord stopWord);
}
/**
 * <p>
 * 禁用词 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TStopWordServiceImpl extends ServiceImpl<StopWordMapper, StopWord> implements ITStopWordService {
    @Resource
    private StopWordMapper stopWordMapper;

    @Resource
    private StringRedisTemplate stringRedisTemplate;
    @Resource
    MsStopWordMapper msStopWordMapper;

    @Override
    public PageDTO<StopWordDTO> listpage(StopWordQuery query) {
        //构建分页条件对象
        Page<StopWord> page = new Page<>(query.getPageSize(),query.getPageIndex());
        //构建查询条件
        QueryWrapper<StopWord> queryWrapper = new QueryWrapper<>();
        queryWrapper.like("title",query.getTitle());
        //执行查询
        Page<StopWord> result = baseMapper.selectPage(page,queryWrapper);
        return PageDTO.create(result,src->msStopWordMapper.StopWordToStopWordDTO(src));
    }

    @Override
    public int updateWord(UpdateWordDTO updateWord,String token) {
        //TODO: 后面看从哪里获取token

        //数据封装
        StopWord stopWord = new StopWord();
        stopWord.setId(updateWord.getId());
        stopWord.setTitle(updateWord.getTitle());
        int count = stopWordMapper.updateById(stopWord);
        return count;
    }
    @Override
    public StopWordDTO findByTitle(String title) {
        LambdaQueryWrapper<StopWord> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(StopWord::getTitle, title);
        StopWord stopWord = baseMapper.selectOne(wrapper);
        StopWordDTO stopWordDTO = new StopWordDTO();
        BeanUtils.copyProperties(stopWord, stopWordDTO);
        return stopWordDTO;
//        LambdaQueryWrapper<StopWordDTO> wrapper = new LambdaQueryWrapper<>();
//        wrapper.eq(StopWordDTO::getTitle, title);
//        return baseMapper.selectOne(wrapper);
    }
}
