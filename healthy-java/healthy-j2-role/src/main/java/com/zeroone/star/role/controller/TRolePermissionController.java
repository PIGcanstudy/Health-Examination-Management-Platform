package com.zeroone.star.role.controller;


import com.zeroone.star.project.j2.RoleApis;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.poi.ss.formula.functions.T;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 角色资源关系映射 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@RequestMapping("/role/t-role-permission")
@Api(tags = "角色权限管理接口")
public class TRolePermissionController implements RoleApis {


    @PostMapping("RolePermission")
    @ApiOperation(value = "设置角色权限")
    @Override
    public JsonVO<MessageDTO> roleDTO(RoleDTO roleDTO) {
        return null;
    }

}

