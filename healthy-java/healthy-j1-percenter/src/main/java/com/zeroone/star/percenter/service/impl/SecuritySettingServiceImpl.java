package com.zeroone.star.percenter.service.impl;

import com.zeroone.star.percenter.service.EncryptionService;
import com.zeroone.star.percenter.service.SecuritySettingService;
import com.zeroone.star.percenter.service.UserService;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.dto.percenter.entity.TUser;
import org.springframework.beans.factory.annotation.Autowired;

/**
 * 服务实现类，用于处理安全设置相关的业务，修改密码和手机。
 */
public class SecuritySettingServiceImpl implements SecuritySettingService {

    // 用户服务，用于执行与用户数据相关的操作，如获取当前用户、更新密码等。
    private final UserService userService;

    // 加密服务，用于密码的加密和校验。
    private final EncryptionService encryptionService;

    @Autowired
    public SecuritySettingServiceImpl(UserService userService, EncryptionService encryptionService) {
        this.userService = userService;
        this.encryptionService = encryptionService;
    }

    /**
     * 修改密码的实现。
     *
     * @param modifyPasswordDTO 包含旧密码和新密码的数据传输对象。
     * @throws Exception 如果旧密码不匹配或者更新过程中发生错误。
     */
    @Override
    public void changePassword(ModifyPasswordDTO modifyPasswordDTO) throws Exception {
        // 获取当前登录的用户信息
        TUser currentUser = userService.getCurrentUser();

        // 加密用户提供的旧密码
        String encryptedOldPassword = encryptionService.encrypt(modifyPasswordDTO.getOldPassword());

        // 检查加密后的旧密码是否与数据库中的密码匹配
        if (!encryptedOldPassword.equals(currentUser.getPassword())) {
            throw new Exception("旧密码不正确");
        }

        // 加密新密码
        String encryptedNewPassword = encryptionService.encrypt(modifyPasswordDTO.getNewPassword());

        // 更新用户的密码
        userService.updatePassword(currentUser.getId(), encryptedNewPassword);
    }


    /**
     * 修改手机号的实现。
     *
     * @param modifyPhoneDTO 包含新手机号的数据传输对象。
     * @throws Exception 如果更新过程中发生错误。
     */
    @Override
    public void changePhone(ModifyPhoneDTO modifyPhoneDTO) throws Exception {
        // 获取当前登录的用户信息
        TUser currentUser = userService.getCurrentUser();

        // 更新用户的手机号
        userService.updatePhone(currentUser.getId(), modifyPhoneDTO.getNewPhone());
    }
}
