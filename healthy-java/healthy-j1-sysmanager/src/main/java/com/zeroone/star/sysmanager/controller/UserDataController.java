package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j1.sysmanager.UserDataApis;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

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
    @GetMapping("/setUserStatus/{status}")
    @ApiImplicitParam(name = "status",required = true)
    public JsonVO setUserStatus(@PathVariable Integer status){
        return JsonVO.success(null);
    }

    @Override
    @GetMapping("/queryUserData/{id}")
    @ApiImplicitParam(name = "id",required = true)
    @ApiOperation("获取用户信息")
    public JsonVO<UserDataVO> queryUserData(@PathVariable Long id) {
        return JsonVO.success(null);
    }
}
