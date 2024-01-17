package com.zeroone.star.project.j1.sysmanager;

import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 系统管理-用户管理，获取、修改、删除用户信息、状态相关接口
 */
public interface UserDataApis {
    JsonVO<List<UserNameListVO>> queryUserNameList();
    JsonVO setUserStatus(Integer status);
    JsonVO<UserDataVO> queryUserData(Long id);

	// 修改用户之前查询用户信息
	JsonVO<ModifyUserDTO> queryUserWhenModifying(String id);
	// 修改用户信息
	void modifyUser(ModifyUserDTO user);
}
