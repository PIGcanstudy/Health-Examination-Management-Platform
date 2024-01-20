package com.zeroone.star.department.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.zeroone.star.department.entity.TDepartment;
import com.zeroone.star.department.mapper.TDepartmentMapper;
import com.zeroone.star.department.service.ITDepartmentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.department.DepartmentMenuVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 部门 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Service
public class TDepartmentServiceImpl extends ServiceImpl<TDepartmentMapper, TDepartment> implements ITDepartmentService {

    @Override
    public List<DepartmentMenuVO> selectById(int parentId) {
        List<TDepartment> menus = baseMapper.selectById(parentId);
        return menus.stream()
                .map(TDepartmentServiceImpl::convertDOToVO)
                .collect(Collectors.toList());
    }

    public static DepartmentMenuVO convertDOToVO(TDepartment employeeDO) {
        DepartmentMenuVO employeeVO = new DepartmentMenuVO();
        employeeVO.setId(employeeDO.getId());
        employeeVO.setSortOrder(employeeDO.getSortOrder());
        employeeVO.setCreateTime(employeeDO.getCreateTime());
        employeeVO.setTitle(employeeDO.getTitle());

        return employeeVO;
    }
}
