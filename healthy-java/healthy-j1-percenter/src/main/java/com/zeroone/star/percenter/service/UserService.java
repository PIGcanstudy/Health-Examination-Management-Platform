package com.zeroone.star.percenter.service;

import com.zeroone.star.project.j1.dto.percenter.entity.TUser;

/**
 * 用户服务接口，用于处理用户相关操作。
 */
public interface UserService {

    /**
     * 获取当前登录的用户。
     *
     * @return 当前登录的用户。
     * @throws Exception 如果获取用户失败。
     */
    TUser getCurrentUser() throws Exception;


    /**
     * 更新用户密码。
     * @param userId 用户ID。
     * @param newPassword 加密后的新密码。
     * @throws Exception 如果更新失败。
     */
    void updatePassword(String userId, String newPassword) throws Exception;


    /**
     * 更新用户手机号。
     * @param userId 用户ID。
     * @param newPhone 新手机号。
     * @throws Exception 如果更新失败。
     */
    void updatePhone(String userId, String newPhone) throws Exception;
}