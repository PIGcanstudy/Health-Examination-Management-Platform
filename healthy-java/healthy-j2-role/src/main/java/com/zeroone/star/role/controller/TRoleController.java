package com.zeroone.star.role.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.RoleApis;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.j2.dto.RoleNameDTO;
import com.zeroone.star.project.j2.query.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 角色 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@RequestMapping("/role/t-role")
public class TRoleController implements RoleApis {
    
    @Override
    public JsonVO<RoleNameDTO> queryAllNames() {
        return null;
    }
    
    @Override
    public JsonVO<PageDTO<RoleDTO>> queryByCondition(RoleQuery roleQuery) {
        return null;
    }
}

