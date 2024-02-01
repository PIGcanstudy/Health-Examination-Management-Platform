package com.zeroone.star.terminologymanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.terminologymanagement.entity.TOfficeTerm;
import com.zeroone.star.terminologymanagement.mapper.TOfficeTermMapper;
import com.zeroone.star.terminologymanagement.service.ITOfficeTermService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 科室术语表 服务实现类
 * </p>
 *
 * @author Laputa
 * @since 2024-01-30
 */
@Service
public class TOfficeTermServiceImpl extends ServiceImpl<TOfficeTermMapper, TOfficeTerm> implements ITOfficeTermService {

    @Override
    public Boolean switchTerm(SwitchTermQuery query) throws Exception {
        UpdateWrapper updateWrapper = new UpdateWrapper();
        updateWrapper.eq("id", query.getId());
        updateWrapper.set("status", query.getStatus());
        int num = baseMapper.update(null, updateWrapper);
        if (num == 0) {
            return false;
        }
        return true;
    }
}
