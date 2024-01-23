package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.TUserDO;
import com.zeroone.star.sysmanager.mapper.UserPasswordMapper;
import com.zeroone.star.sysmanager.service.UserPasswordService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Objects;

/**
 * <p>
 * 用户 服务实现类
 * </p>
 *
 * @author light
 * @since 2024-01-18
 */
@Service("userPasswordService")
public class UserPasswordServiceImpl extends ServiceImpl<UserPasswordMapper, TUserDO> implements UserPasswordService {
    /**
     * 修改密码
     * @param modifyPasswordDTO 修改密码DTO
     * @return
     */


    @Autowired
    UserHolder userHolder;

    @Override
    public JsonVO updatePasswordToChange(ModifyPasswordDTO modifyPasswordDTO) {
        // 判断当前登录的用户是否为管理员账号(type字段是否为1)
        // 假设当前登录的用户为admin用户 TODO 获取当前登录的用户id，这里进行了模拟
        // String currentUserId = "682265633886208";
        String currentUserId;
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            currentUserId = currentUser.getId().toString();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        TUserDO currentUserDO = getBaseMapper().selectById(currentUserId);
        // 被修改密码的用户
        TUserDO changeUser = getBaseMapper().selectById(modifyPasswordDTO.getId());
        // 判断被修改密码的用户是否存在
        if(Objects.isNull(changeUser)){
            return JsonVO.create(null,8000,"用户id非法");
        }
        // 不是管理员则提示没有权限
        if(currentUserDO.getType() != 1){
            return JsonVO.create(null, ResultStatus.FORBIDDEN);
        }
        // 判断被修改密码的用户的新密码与旧密码是否相同
        if(modifyPasswordDTO.getPassword().equals(modifyPasswordDTO.getNew_password())){
            return JsonVO.create(null,9991,"新密码不能与现在的密码相同");
        }
        // 验证被修改用户的旧密码是否正确
        // TODO 问题：应该是要调用别人的密码验证服务来实现,因为这里没有BCryptPasswordEncoder这个Bean,这里进行使用new进行了模拟的实现
        BCryptPasswordEncoder bCryptPasswordEncoder = new BCryptPasswordEncoder();
        boolean matches = bCryptPasswordEncoder.matches(modifyPasswordDTO.getPassword(),changeUser.getPassword());
        if(!matches){
            return JsonVO.create(null,9990,"旧密码输入有误");
        }
        // 使用加密后的新密码替换原来的密码,同时更改密码强度
        String encodePassword = bCryptPasswordEncoder.encode(modifyPasswordDTO.getNew_password());
        UpdateWrapper<TUserDO> tUserUpdateWrapper = new UpdateWrapper<>();
        tUserUpdateWrapper
                .set("password",encodePassword)
                .set("pass_strength",modifyPasswordDTO.getPass_strength())
                .eq("id",modifyPasswordDTO.getId());
        getBaseMapper().update(null,tUserUpdateWrapper);
        return JsonVO.success(null);
    }

    /**
     * 重置密码
     * @param ids 被重置密码的用户id
     * @return
     */
    @Override
    public JsonVO updatePasswordToReset(List<String> ids) {
        // 判断是否选择了被重置密码的用户
        if(ids == null || ids.size() == 0){
            return JsonVO.create(null,8001,"请选择需要被重置密码的用户");
        }
        // 判断当前用户是否为管理员身份 TODO 获取当前登录的用户id，这里进行了模拟
        String currentUserId = "682265633886208";
        TUserDO currentUserDO = getBaseMapper().selectById(currentUserId);
        // 不是管理员则提示权限不足
        if(currentUserDO.getType() != 1){
            return JsonVO.create(null, ResultStatus.FORBIDDEN);
        }

        // 被重置密码的用户中有管理员用户时就不能进行重置操作
        for(String id : ids){
            LambdaQueryWrapper<TUserDO> tUserLambdaQueryWrapper = new LambdaQueryWrapper<>();
            tUserLambdaQueryWrapper
                    .select(TUserDO::getId, TUserDO::getType)
                    .eq(TUserDO::getId,id);
            TUserDO tUserDO = getBaseMapper().selectOne(tUserLambdaQueryWrapper);
            // 判断数据库中是否存在数据
            if(Objects.isNull(tUserDO)){
                return JsonVO.create(null,8005,"存在非法的用户id");
            }
            if(tUserDO.getType() == 1){
                return JsonVO.create(null,8004,"不能重置管理员的密码");
            }
        }
        // 执行重置操作，重置选中用户的密码为123456
        for(String id : ids){
            BCryptPasswordEncoder bCryptPasswordEncoder = new BCryptPasswordEncoder();
            String password = bCryptPasswordEncoder.encode("123456");
            UpdateWrapper<TUserDO> tUserUpdateWrapper = new UpdateWrapper<>();
            tUserUpdateWrapper
                    .set("password",password)
                    .eq("id",id);
            getBaseMapper().update(null,tUserUpdateWrapper);
        }
        return JsonVO.success(null);
    }
}
