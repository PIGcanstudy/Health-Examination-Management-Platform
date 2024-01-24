package com.zeroone.star.percenter.service.impl;

import com.zeroone.star.percenter.service.UserService;
import com.zeroone.star.project.j1.dto.percenter.entity.TUser;


public class UserServiceImpl implements UserService {
    // 假设您有一个用户Mapper或者Repository来处理数据库操作
    private final UserMapper userMapper;

    @Override
    public TUser getCurrentUser() throws Exception {
        // 需要根据您的安全框架来获取当前用户

        String currentUserId = xxx; // 从安全上下文获取当前用户ID
        return userMapper.selectById(currentUserId);
    }

    @Override
    public void updatePassword(String userId, String newPassword) throws Exception {
        TUser user = userMapper.selectById(userId);
        user.setPassword(newPassword);
        userMapper.updateById(user);
    }

    @Override
    public void updatePhone(String userId, String newPhone) throws Exception {
        TUser user = userMapper.selectById(userId);
        user.setMobile(newPhone);
        userMapper.updateById(user);
    }
}