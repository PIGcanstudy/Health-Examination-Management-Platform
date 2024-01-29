package com.zeroone.star.percenter.mapper;

import com.zeroone.star.percenter.entity.TUser;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j1.dto.percenter.ModifyPersonalInfoDTO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 用户 Mapper 接口
 * </p>
 *
 * @author feng
 * @since 2024-01-25
 */
@Mapper
public interface TUserMapper extends BaseMapper<TUser> {


    /**
     * 修改个人信息
     * @param tUser
     */
    void updatePersonalInfo(TUser tUser);
}
