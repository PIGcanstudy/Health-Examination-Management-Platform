package com.zeroone.star.project.j2.query;

<<<<<<< HEAD
=======
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
>>>>>>> origin/j2-role-xiaoye
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

<<<<<<< HEAD
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：角色查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author shun
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("角色查询对象")
public class RoleQuery extends PageQuery {
    @ApiModelProperty(value = "角色名称", example = "张三")
    private String name;



=======
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：设置角色菜单和数据权限
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author xiaoye
 * @version 1.0.0
 */
@Data
@ApiModel("设置角色菜单和数据权限")
public class RoleQuery extends PageQuery {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识", example = "1")
    private String id;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建人", example = "萧炎")
    private String createBy;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2024-01-19T17:08:02.225")
    @TableField(fill = FieldFill.INSERT)
    private String createTime;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人", example = "tom")
    private String updateBy;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间", example = "2024-01-19T17:08:02.225")
    private String updateTime;

    /**
     * 角色名称，命名规则以 “ROLE_” 开头，如ROLE_TEST
     */
    @ApiModelProperty(value = "角色名称", example = "ROLE_Tom")
    private String name;

    /**
     * 逻辑删除标识 0 未删除 1 已删除
     */
    @ApiModelProperty(value = "逻辑删除标识", example = "1")
    private Boolean delFlag;

    /**
     * 是否为注册默认包含角色 0 否 1 是
     */
    @ApiModelProperty(value = "是否为注册默认包含角色", example = "1")
    private Boolean defaultRole;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "无")
    private String description;

    /**
     * 数据权限 0全部 1自定义 2本部门及以下 3本部门
     */
    @ApiModelProperty(value = "数据权限", example = "0")
    private Boolean dataType;
>>>>>>> origin/j2-role-xiaoye
}
