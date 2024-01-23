package com.zeroone.star.role.controller;


import com.zeroone.star.project.j2.RoleApis;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
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
    @PostMapping("add-role")
    @ApiOperation(value = "新增角色权限")
    @Override
    public JsonVO<RoleDTO> addRoleDTO(RoleDTO roleDTO) {
        return null;
    }

    @GetMapping
    @ApiOperation(value = "获取角色菜单权限")
    @Override
    public JsonVO<RoleDTO> queryRoleMenu(long id) {
        return null;
    }


}

