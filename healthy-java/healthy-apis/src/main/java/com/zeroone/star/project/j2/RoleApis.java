package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.RoleNameDTO;
import com.zeroone.star.project.j2.query.RoleQuery;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface RoleApis {

    /**
     * 新增角色
     *
     * @param roleDTO
     * @return
     */
    JsonVO<RoleDTO> addRoleDTO(RoleDTO roleDTO);

    /**
     * 查看角色菜单权限
     *
     * @param id
     * @return
     */
    JsonVO<RoleDTO> queryRoleMenu(long id);

    /**
     * 获取角色名称列表
     *
     * @return 默认分页的角色名称列表
     */
    JsonVO<RoleNameDTO> queryAllNames();

    /**
     * 获取分页+条件角色列表
     *
     * @param roleQuery 查询条件和分页信息
     * @return 符合条件的角色列表
     */

    JsonVO<PageDTO<RoleDTO>> queryByCondition(RoleQuery roleQuery);

}
