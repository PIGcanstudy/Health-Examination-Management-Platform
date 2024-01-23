package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.UserDTO;
import com.zeroone.star.project.j1.query.sysmanager.UserListQuery;
import com.zeroone.star.project.j1.sysmanager.UserDataApis;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-用户数据")
public class UserDataController implements UserDataApis {
    /**
     * 获取用户名称列表（用于输入表单下拉列表框）
     * @return
     */
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

    /**
     * 获取用户列表（条件 + 分页）
     * @param userListQuery 查询条件 + 分页条件
     * @return
     */
    @Override
    @GetMapping("/query-user-list")
    @ApiOperation("获取用户列表（条件 + 分页）")
    public JsonVO<PageDTO<UserDTO>> queryUserList(UserListQuery userListQuery) {
        return JsonVO.success(new PageDTO<UserDTO>());
    }

    /**
     * 设置用户状态
     * @param status 需要改成的状态
     * @return
     */
    @Override
    @GetMapping("/set-user-status/{status}")
    @ApiImplicitParam(name = "status",required = true)
    @ApiOperation("设置用户状态")
    public JsonVO setUserStatus(@PathVariable Integer status){
        return JsonVO.success(null);
    }

    /**
     * 获取用户详情
     * @param id 用户id
     * @return
     */
    @Override
    @GetMapping("/query-user-data/{id}")
    @ApiImplicitParam(name = "id",required = true)
    @ApiOperation("获取用户详情")
    public JsonVO<UserDataVO> queryUserData(@PathVariable Long id) {
        return JsonVO.success(null);
    }

    /**
     * 修改用户信息
     * @param user 用户实体
     * @return
     */
	@Override
    @PutMapping("/modify-user-info")
    @ApiOperation("修改用户信息")
	public JsonVO modifyUser(@RequestBody ModifyUserDTO user) {
        return JsonVO.success("修改成功");
	}

    /**
     * 新增用户
     * @param user 用户实体
     * @return
     */
    @Override
    @PostMapping("/add-user")
    @ApiOperation("新增用户")
    public JsonVO createUser(@RequestBody CreateUserDTO user) {
        return JsonVO.success("新增成功");
    }

    /**
     * 批量删除用户
     * @param ids 用户id
     * @return
     */
    @Override
    @DeleteMapping("/delete-user-list")
    @ApiOperation("批量删除用户")
    public JsonVO deleteUserList(@RequestBody List<String> ids) {
        return JsonVO.success("删除成功");
    }
}
