package com.zeroone.star.sysmanager.service.impl;

import com.alibaba.nacos.shaded.org.checkerframework.checker.units.qual.A;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.entiy.Role;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.mapper.RoleMapper;
import com.zeroone.star.sysmanager.mapper.UserMapper;
import com.zeroone.star.sysmanager.service.UserService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
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
        userMapper.updateUserStatus(id,status);
    }

    @Override
    public UserDataVO getUserData(Long id) {
        TUser tUser = userMapper.selectById(id);
        UserDataVO userDataVO = new UserDataVO();
        BeanUtils.copyProperties(tUser,userDataVO);
        List<Role> rolelist= roleMapper.selectRoleByUserId(id);
        userDataVO.setRoleList(rolelist);
        return userDataVO;
    }
}
