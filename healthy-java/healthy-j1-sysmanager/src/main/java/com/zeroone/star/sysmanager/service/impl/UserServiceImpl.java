package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.entiy.Role;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.mapper.RoleMapper;
import com.zeroone.star.sysmanager.mapper.UserMapper;
import com.zeroone.star.sysmanager.service.UserService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    private UserMapper userMapper;

    @Autowired
    private RoleMapper roleMapper;
    @Override
    public void setUserStatus(Long id, Integer status) {
        TUser tUser = userMapper.selectById(id);
        if (tUser == null) {
            throw new RuntimeException("用户不存在");
        }
        if (status == null) {
            throw new RuntimeException("状态不能为空");
        }
        userMapper.updateUserStatus(id,status);
    }

    @Override
    public UserDataVO getUserData(Long id) {
        TUser tUser = userMapper.selectById(id);
        if (tUser == null) {
            throw new RuntimeException("用户不存在");
        }
        UserDataVO userDataVO = new UserDataVO();
        BeanUtils.copyProperties(tUser,userDataVO);
        List<Role> rolelist = roleMapper.selectRoleByUserId(id);
        userDataVO.setRoleList(rolelist);
        return userDataVO;
    }

}
