package com.zeroone.star.role.service.impl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.j2.dto.RoleNameDTO;
import com.zeroone.star.project.j2.query.RoleQuery;
import com.zeroone.star.role.entity.TRole;
import com.zeroone.star.role.mapper.TRoleMapper;
import com.zeroone.star.role.service.ITRoleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 角色 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Service
public class TRoleServiceImpl extends ServiceImpl<TRoleMapper, TRole> implements ITRoleService {
    //获取角色名称列表
    RoleNameDTO getRoleNames(){
        return null;
    }
    
    //条件加分页查询角色列表
    PageDTO<RoleDTO> getByCondition(RoleQuery roleQuery){
        return  null;
    }
}
