package com.zeroone.star.percenter.service.impl;

import com.zeroone.star.percenter.entity.TUser;
import com.zeroone.star.percenter.mapper.TUserMapper;
import com.zeroone.star.percenter.service.ITUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 用户 服务实现类
 * </p>
 *
 * @author feng
 * @since 2024-01-25
 */
@Service
public class TUserServiceImpl extends ServiceImpl<TUserMapper, TUser> implements ITUserService {

    @Resource
    private UserHolder userHolder;      // 用户信息获取组件

    @Resource
    private PasswordEncoder passwordEncoder;        // 处理密码的加密和验证


    /**
     * 更新用户密码。
     * 该方法首先获取当前用户信息，验证旧密码，然后更新为新密码。
     *
     * @param modifyPasswordDTO 包含旧密码和新密码的数据传输对象
     * @return JsonVO<String> 表示操作结果，成功或失败信息
     */
    public JsonVO<String> modifyPassword(ModifyPasswordDTO modifyPasswordDTO) {
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            Integer userId = currentUser.getId();

            TUser user = this.getById(userId);
            if (user == null) {
                return JsonVO.fail("用户不存在");
            }

            // 使用PasswordEncoder来验证密码
            if (!passwordEncoder.matches(modifyPasswordDTO.getOldPassword(), user.getPassword())) {
                return JsonVO.fail("旧密码不正确");
            }

            // 使用PasswordEncoder来加密新密码
            user.setPassword(passwordEncoder.encode(modifyPasswordDTO.getNewPassword()));
            this.updateById(user);

            return JsonVO.success("密码更新成功");
        } catch (Exception e) {
            return JsonVO.fail("密码更新失败: " + e.getMessage());
        }
    }


    //@Autowired
    //private VerificationCodeService verificationCodeService;    // 验证码服务

    ///**
    // * 更新用户手机号。
    // * 该方法首先验证提供的验证码，然后更新用户的手机号信息。
    // *
    // * @param modifyPhoneDTO 包含新手机号和验证码的数据传输对象
    // * @return JsonVO<String> 表示操作结果，成功或失败信息
    // */
    //public JsonVO<String> modifyPhone(ModifyPhoneDTO modifyPhoneDTO) {
    //    try {
    //        UserDTO currentUser = userHolder.getCurrentUser();
    //        Integer userId = currentUser.getId();
    //
    //        if (!verificationCodeService.checkCode(modifyPhoneDTO.getNewPhone(), modifyPhoneDTO.getVerificationCode())) {
    //            return JsonVO.fail("验证码不正确或已过期");
    //        }
    //
    //        TUser user = this.getById(userId);
    //        if (user == null) {
    //            return JsonVO.fail("用户不存在");
    //        }
    //
    //        user.setMobile(modifyPhoneDTO.getNewPhone());
    //        this.updateById(user);
    //
    //        return JsonVO.success("手机号更新成功");
    //    } catch (Exception e) {
    //        return JsonVO.fail("手机号更新失败: " + e.getMessage());
    //    }
    //}
}
