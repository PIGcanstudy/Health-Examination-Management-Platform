package com.zeroone.star.department.service.impl;

import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.zeroone.star.department.entity.TDepartment;
import com.zeroone.star.department.mapper.TDepartmentMapper;
import com.zeroone.star.department.service.ITDepartmentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 部门 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Service
@RequiredArgsConstructor
public class TDepartmentServiceImpl extends ServiceImpl<TDepartmentMapper, TDepartment> implements ITDepartmentService {

    private final TDepartmentMapper departmentMapper;

    @Override
    public void updateUpdateBy(String[] ids, String username) {
        LambdaUpdateWrapper<TDepartment> updateWrapper = Wrappers.lambdaUpdate();
        updateWrapper.set(TDepartment::getUpdateBy, username);
        updateWrapper.in(TDepartment::getId, ids);
        update(updateWrapper);
    }
}
