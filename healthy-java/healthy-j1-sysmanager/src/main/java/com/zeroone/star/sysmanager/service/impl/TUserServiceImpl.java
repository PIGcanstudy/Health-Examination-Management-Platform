package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.entity.TUserRole;
import com.zeroone.star.sysmanager.mapper.DepartmentMapper;
import com.zeroone.star.sysmanager.mapper.TUserMapper;
import com.zeroone.star.sysmanager.mapper.UserRoleMapper;
import com.zeroone.star.sysmanager.service.ITUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.extern.slf4j.Slf4j;
import org.mapstruct.Mapper;
import org.springframework.cache.annotation.Cacheable;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

/**
 * User对应的MapStruct映射接口
 */
@Mapper(componentModel = "spring")
interface MsUserMapper{
    /**
     * 将 TUser 转成 UserNameListVO
     * @param user 待转换的DO
     * @return 转换结果
     */
    UserNameListVO userToUserNameListVO(TUser user);

    /**
     * 将 CreateUserDTO 转换成 TUser
     * @param createUserDTO 待转换的DTO
     * @return 转换结果
     */
    TUser CreateUserDTOToTUser(CreateUserDTO createUserDTO);
}
/**
 * <p>
 * 用户 服务实现类
 * </p>
 *
 * @author 阿布
 * @since 2024-01-23
 */
@Service
public class TUserServiceImpl extends ServiceImpl<TUserMapper, TUser> implements ITUserService {

    @Resource
    private MsUserMapper msUserMapper;

    /**
     * t_user表相关的Mapper
     */
    @Resource
    private TUserMapper tUserMapper;

    @Resource
    private UserHolder userHolder;

    @Resource
    private DepartmentMapper departmentMapper;

    @Resource
    private UserRoleMapper userRoleMapper;

    /**
     * 获取用户名称列表（用于输入表单下拉列表框）
     * @return
     */
    @Override
    public List<UserNameListVO> listUsernameList() {
        QueryWrapper<TUser> wrapper = new QueryWrapper<>();
        List<TUser> users = tUserMapper.selectList(wrapper);
        List<UserNameListVO> list = new ArrayList<>();
        if (BeanUtil.isNotEmpty(users) && users.size() > 0) {
            for (TUser user : users) {
                UserNameListVO userNameListVO = msUserMapper.userToUserNameListVO(user);
                list.add(userNameListVO);
            }
        }
        return list;
    }

	@Override
	public void modifyUser(ModifyUserDTO user) {
        // TODO 测试未通过，待修改
        /*
        报错如下：
        "JSON parse error: Cannot deserialize value of type
        `java.time.LocalDateTime` from String \"2000/1/1\":
        Failed to deserialize java.time.LocalDateTime:
         */
		TUser tUser = new TUser();
		tUser.setId(user.getId());
		tUser.setUsername(user.getUsername());
		tUser.setNickname(user.getNickName());
		tUser.setEmail(user.getEmail());
		tUser.setMobile(user.getMobile());
		tUser.setSex(user.getSex());
		tUser.setDepartmentId(user.getDepartmentId());
		tUser.setType(user.getType());
		tUser.setAvatar(user.getAvatar());
		tUser.setAddress(user.getAddress());
		tUser.setStreet(user.getStreet());
		tUser.setAutograph(user.getAutograph());
		tUser.setBirth(user.getBirth());
		tUser.setDescription(user.getDescription());
		tUser.setDelFlag(false);
		tUserMapper.updateById(tUser);
	}

    /**
     * 新增用户
     * @param createUserDTO
     */
    @Override
    @Transactional
    public void saveUser(CreateUserDTO createUserDTO) {
        // 获取当前用户信息
        TUser tUser = getUserByToken();
        if (tUser.getType() != 1) {
            throw new RuntimeException("用户权限不足");
        }

        // 将DTO转换成TUser实体
        TUser user = msUserMapper.CreateUserDTOToTUser(createUserDTO);
        // 设置新增、修改的时间和修改人
        user.setCreateBy(tUser.getUsername());
        user.setUpdateBy(tUser.getUsername());
        user.setCreateTime(LocalDateTime.now());
        user.setUpdateTime(LocalDateTime.now());
        // 设置逻辑删除标记为未删除(0)
        user.setDelFlag(false);
        // 获取部门名称
        String departmentTitle = departmentMapper.selectTitleById(tUser.getDepartmentId());
        user.setDepartmentTitle(departmentTitle);
        // 设置账号状态为启用(0)
        user.setStatus(0);
        // 新增用户
        save(user);

        // 为新账号添加角色
        List<Long> roleIds = createUserDTO.getRoleIds();
        if (BeanUtil.isNotEmpty(roleIds) && roleIds.size() > 0) {
            List<TUserRole> list = new ArrayList<>();
            for (Long roleId : roleIds) {
                TUserRole tUserRole = new TUserRole();
                tUserRole.setCreateBy(tUser.getUsername());
                tUserRole.setCreateTime(LocalDateTime.now());
                tUserRole.setDelFlag(false);
                tUserRole.setUpdateBy(tUser.getUsername());
                tUserRole.setUpdateTime(LocalDateTime.now());
                tUserRole.setRoleId(roleId);
                tUserRole.setUserId(user.getId());
                list.add(tUserRole);
            }
            userRoleMapper.insert(list);
        }
    }

    /**
     * 从userHolder中获取用户信息
     * @return
     */
    public TUser getUserByToken() {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException(ResultStatus.UNAUTHORIZED.getMessage());
        }
        Long userId = currentUser.getId();
        TUser user = tUserMapper.selectById(userId);
        if (user == null || user.getDelFlag()) {
            throw new RuntimeException("用户不存在");
        }
        if (user.getStatus() == 1) {
            throw new RuntimeException("用户处于禁用状态");
        }
        return user;
    }


}
