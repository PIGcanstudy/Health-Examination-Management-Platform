package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.j2.dto.RoleNameDTO;
import com.zeroone.star.project.j2.query.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：对象查询接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface RoleApis {
    /**
     * 获取角色名称列表
     * @return 默认分页的角色名称列表
     */
    JsonVO<RoleNameDTO> queryAllNames();
    
    /**
     * 获取分页+条件角色列表
     * @param roleQuery 查询条件和分页信息
     * @return 符合条件的角色列表
     */
    
    JsonVO<PageDTO<RoleDTO>> queryByCondition(RoleQuery roleQuery);
}
