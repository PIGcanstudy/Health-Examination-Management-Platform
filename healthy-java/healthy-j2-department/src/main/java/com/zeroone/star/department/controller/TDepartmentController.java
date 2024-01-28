package com.zeroone.star.department.controller;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.department.entity.TDepartment;
import com.zeroone.star.department.service.ITDepartmentService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j2.DepartmentApis;
import com.zeroone.star.project.j2.dto.DepartmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import java.util.Arrays;

/**
 * <p>
 * 部门 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */

@Api(tags = "部门管理")
@RestController
@RequiredArgsConstructor
@RequestMapping("/department/t-department")
public class TDepartmentController implements DepartmentApis {

    private final ITDepartmentService departmentService;

    UserHolder userHolder=new UserHolder();

    @Override
    @ApiOperation("添加部门")
    @PostMapping("add-department")
    public JsonVO<Integer> addDepartment(@RequestBody DepartmentDTO department) {
        TDepartment tDepartment = BeanUtil.copyProperties(department, TDepartment.class);
        //从请求头中获取创建人信息,前端不传时间信息,让数据库自动生成
        try {
            tDepartment.setCreateBy(userHolder.getCurrentUser().getUsername());
            if (!departmentService.save(tDepartment)) {
                return JsonVO.fail(0);
            }
            return JsonVO.success(1);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    @ApiOperation("删除部门")
    @PostMapping("remove-department/{ids}")
    public JsonVO<Integer> removeDepartment(@PathVariable String[] ids) {
        try {
            //删除部门也是修改,需要更新修改者字段
            departmentService.updateUpdateBy(ids,userHolder.getCurrentUser().getUsername());
            if (!departmentService.removeByIds(Arrays.asList(ids))) {
                return JsonVO.fail(0);
            }
            return JsonVO.success(ids.length);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    @ApiOperation("修改部门")
    @PatchMapping("modify-department")
    public JsonVO<Integer> modifyDepartment(@RequestBody DepartmentDTO department) {
        TDepartment tDepartment = BeanUtil.copyProperties(department, TDepartment.class);
        //从请求头中获取修改人信息
        try {
            tDepartment.setUpdateBy(userHolder.getCurrentUser().getUsername());
            if (!departmentService.updateById(tDepartment)) {
                return JsonVO.fail(0);
            }
            return JsonVO.success(1);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

}

