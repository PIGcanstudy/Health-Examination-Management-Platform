package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.percenter.entity.TUser;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.UserDTO;
import com.zeroone.star.project.j1.query.sysmanager.UserListQuery;
import com.zeroone.star.project.j1.sysmanager.UserDataApis;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.sysmanager.service.ITUserService;
import com.zeroone.star.sysmanager.service.UserDataService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import lombok.extern.java.Log;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cache.annotation.Cacheable;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Slf4j
@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-用户数据")
public class UserDataController implements UserDataApis {


    @Resource
    private ITUserService itUserService;



    @Autowired
    private UserDataService userDataService;
    /**
     * 获取用户名称列表（用于输入表单下拉列表框）
     * @return
     */
    @Override
    @GetMapping("/query-username-list")
    @ApiOperation("获取用户名称列表（用于输入表单下拉列表框）")
    @Cacheable(cacheNames = "UserNameListVOCache", key = "")
    public JsonVO<List<UserNameListVO>> queryUserNameList() {
        List<UserNameListVO> list = itUserService.listUsernameList();
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
		itUserService.modifyUser(user);
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
        try {
            // 将DTO转换为TUser实体
            TUser tuser = convertDTOToEntity(user);

            // 调用UserService的方法保存用户
            userDataService.createUser(tuser);

            return JsonVO.success("新增成功");
        } catch (Exception e) {
            log.error("新增用户失败", e);
            return JsonVO.fail("新增失败");
        }
    }


    // 辅助方法：将DTO转换为TUser实体
    private TUser convertDTOToEntity(CreateUserDTO createUserDTO) {
        TUser user = new TUser();
        user.setUsername(createUserDTO.getUsername());
        user.setPassword(createUserDTO.getPassword());
        user.setNickname(createUserDTO.getNickname());
        user.setMobile(createUserDTO.getMobile());
        user.setDepartmentTitle(createUserDTO.getDepartmentTitle());
        user.setEmail(createUserDTO.getEmail());
        user.setSex(createUserDTO.getSex());
        user.setType(createUserDTO.getType());
        user.setAvatar(createUserDTO.getAvatar());
        user.setDepartmentId(createUserDTO.getDepartmentId());
        user.setAddress(createUserDTO.getAddress());
        user.setStreet(createUserDTO.getStreet());
        user.setAutograph(createUserDTO.getAutograph());
        user.setBirth(createUserDTO.getBirth());
        user.setDescription(createUserDTO.getDescription());
        return user;
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
        try {
            userDataService.deleteUserList(ids);
            return JsonVO.success("删除成功");
        } catch (Exception e) {
            return JsonVO.fail("删除失败");
        }
    }

}
