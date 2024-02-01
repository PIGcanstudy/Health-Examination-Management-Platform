package com.zeroone.star.term.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.term.common.OrgStructureException;
import com.zeroone.star.term.entity.OfficeTermEntity;
import com.zeroone.star.term.mapper.TermanagementMapper;
import com.zeroone.star.term.service.OfficeTermService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * 科室术语表(OfficeTerm)表服务实现类
 *
 * @author makejava
 * @since 2024-01-30 14:43:18
 */
@Service("officeTermService")
public class OfficeTermServiceImpl extends ServiceImpl<TermanagementMapper, OfficeTermEntity> implements OfficeTermService {
    @Autowired
    OfficeTermService officeTermService;

    @Override
    public void deletetermanagement(Integer office_id) {
//        删除科室false返回异常
        if(!removeById(office_id)){
            throw new OrgStructureException("科室不存在");
        }else {
            removeById(office_id);
        }
    }
}
