package com.zeroone.star.project.j2;

import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface RoleApis {

    /**
     * 新增角色
     * @param roleDTO
     * @return
     */
    JsonVO<RoleDTO> addRoleDTO(RoleDTO roleDTO);

    /**
     * 查看角色菜单权限
     * @param roleDTO
     * @return
     */
    JsonVO<RoleDTO> selectRoleMenu(RoleDTO roleDTO);
}
