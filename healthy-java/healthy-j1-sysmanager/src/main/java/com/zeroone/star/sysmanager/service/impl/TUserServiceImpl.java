package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.mapper.TUserMapper;
import com.zeroone.star.sysmanager.service.ITUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.extern.slf4j.Slf4j;
import org.mapstruct.Mapper;
import org.springframework.cache.annotation.Cacheable;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * User对应的MapStruct映射接口
 */
@Mapper(componentModel = "spring")
interface MsUserMapper{
    /**
     * 将 TUser 转成 UserNameListVO
     * @param user 带转换的DO
     * @return 转换结果
     */
    UserNameListVO userToUserNameListVO(TUser user);
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
    private TUserMapper userMapper;

    /**
     * 获取用户名称列表（用于输入表单下拉列表框）
     * @return
     */
    @Override
    public List<UserNameListVO> listUsernameList() {
        QueryWrapper<TUser> wrapper = new QueryWrapper<>();
        List<TUser> users = userMapper.selectList(wrapper);
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
		userMapper.updateById(tUser);
	}
}
