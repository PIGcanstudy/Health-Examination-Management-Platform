package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.sysmanager.UserDataApis;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-用户数据")
public class UserDataController implements UserDataApis {
    @Override
    @GetMapping("/query-username-list")
    @ApiOperation("获取用户名称列表（用于输入表单下拉列表框）")
    public JsonVO<List<UserNameListVO>> queryUserNameList() {
        UserNameListVO userNameListVO = new UserNameListVO();
        userNameListVO.setId("682265633886208");
        userNameListVO.setNickname("管理员");
        List<UserNameListVO> list = new ArrayList<>();
        list.add(userNameListVO);
        return JsonVO.success(list);
    }

    @Override
    @GetMapping("/set-user-status/{status}")
    @ApiImplicitParam(name = "status",required = true)
    @ApiOperation("设置用户状态")
    public JsonVO setUserStatus(@PathVariable Integer status){
        return JsonVO.success(null);
    }

    @Override
    @GetMapping("/query-user-data/{id}")
    @ApiImplicitParam(name = "id",required = true)
    @ApiOperation("获取用户信息")
    public JsonVO<UserDataVO> queryUserData(@PathVariable Long id) {
        return JsonVO.success(null);
    }

	@Override
	public JsonVO<ModifyUserDTO> queryUserWhenModifying(String id) {
		return null;
	}

	@Override
    @PutMapping("/modify-user-info")
    @ApiOperation("修改用户信息")
	public JsonVO modifyUser(@RequestBody ModifyUserDTO user) {
        return JsonVO.success("修改成功");
	}
}
