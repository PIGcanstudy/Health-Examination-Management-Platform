package com.zeroone.star.tsectionoffice.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.tsectionoffice.entity.TSectionOffice;
import com.zeroone.star.tsectionoffice.mapper.TSectionOfficeMapper;
import com.zeroone.star.tsectionoffice.service.ITSectionOfficeService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.val;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.sql.Wrapper;
import java.time.LocalDateTime;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsTSectionOfficeMapper {
    /**
     * tSectionOffice 转换成 tSectionOfficeDTO
     * @param tSectionOffice 待转换的DO
     * @return 转换结果
     */
    TSectionOfficeDTO tSectionOfficeTotSectionOfficeDTO(TSectionOffice tSectionOffice);
}




/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author AYuan
 * @since 2024-01-16
 */
@Service
public class TSectionOfficeServiceImpl extends ServiceImpl<TSectionOfficeMapper, TSectionOffice> implements ITSectionOfficeService {
    @Resource
    private TSectionOfficeMapper tSectionOfficeMapper;
    // @Resource
    // private MsTSectionOfficeMapper msTSectionOfficeMapper;

    @Override
    public void saveSectionOffice(TSectionOfficeDTO tSectionOfficeDTO) {
        val tSectionOffice = new TSectionOffice();
        // 拷贝数据
        BeanUtils.copyProperties(tSectionOfficeDTO,tSectionOffice);
        // TODO：考虑异常情况
        // 执行插入
        tSectionOfficeMapper.insert(tSectionOffice);
        // tSectionOfficeMapper.insertSectionOffice(tSectionOffice);
    }

    @Override
    public void updateSectionOffice(TSectionOfficeDTO tSectionOfficeDTO) {
        val tSectionOffice = new TSectionOffice();
        // 拷贝数据
        BeanUtils.copyProperties(tSectionOfficeDTO,tSectionOffice);
        // TODO:设定修改人
        tSectionOffice.setUpdateId("1");
        // 设定修改时间
        tSectionOffice.setUpdateTime(LocalDateTime.now());
        // 执行修改
        tSectionOfficeMapper.updateById(tSectionOffice);
    }

    @Override
    public void removeSectionOffice(List<String> ids) {
        QueryWrapper<TSectionOffice> wrapper = new QueryWrapper<>();
        wrapper.in("id", ids);
        tSectionOfficeMapper.delete(wrapper);
    }
}
