package com.zeroone.star.project.j1.vo.sysmanager.entiy;

import cn.hutool.core.date.DateTime;
import io.swagger.models.auth.In;
import lombok.Data;

@Data
public class Role {
    private Integer id;
    /**
     * 创建人
     */
    private Integer createBy;
    /**
     * 创建时间
     */
    private DateTime createTime;
    /**
     * 修改人
     */
    private Integer updateBy;
    /**
     * 修改时间
     */
    private DateTime updateTime;
    /**
     * 角色名称，命名规则以 “ROLE_” 开头，如ROLE_TEST
     */
    private String name;
    /**
     * 逻辑删除标识 0 未删除 1 已删除
     */
    private Integer delFlag;
    /**
     * 是否为注册默认包含角色 0 否 1 是
     */
    private Integer defaultRole;
    /**
     * 备注
     */
    private String description;
    /**
     * 数据权限 0全部 1自定义 2本部门及以下 3本部门
     */
    private Integer dataType;
}
