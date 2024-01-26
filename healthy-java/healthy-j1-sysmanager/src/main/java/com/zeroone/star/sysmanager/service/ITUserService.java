package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.sysmanager.entity.TUser;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 用户 服务类
 * </p>
 *
 * @author 阿布
 * @since 2024-01-23
 */
public interface ITUserService extends IService<TUser> {

    /**
     * 获取用户名称列表（用于输入表单下拉列表框）
     * @return
     */
    List<UserNameListVO> listUsernameList();

	/**
	 * 修改用户
	 * @return
	 */
	void modifyUser(ModifyUserDTO user);
}
