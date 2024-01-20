package com.zeroone.star.department.controller;


import com.zeroone.star.department.service.ITDepartmentService;
import com.zeroone.star.project.j2.DepartmentApis;
import com.zeroone.star.project.j2.dto.DepartmentDTO;
import com.zeroone.star.project.j2.query.DepartmentQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.department.DepartmentMenuVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 部门 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@RequestMapping("/department/t-department")
@Api(tags = "department")
public class TDepartmentController implements DepartmentApis {

    @Resource
    ITDepartmentService departmentService;

    @ApiOperation(value = "获取子部门列表")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<DepartmentMenuVO>> getMenus(int id){
        List<DepartmentMenuVO> menus = departmentService.selectById(id);
        return JsonVO.success(menus);
    }

    /**
     * 获取指定部门详情
     *
     * @param condition 查询条件
     * @return 查询结果
     */
    @ApiOperation(value = "获取部门详情")
    @GetMapping("get-inform")
    @Override
    public JsonVO<DepartmentDTO> queryAll(DepartmentQuery condition) {
        DepartmentDTO dto = new DepartmentDTO();
        dto.setTitle(condition.getTitle());
        return JsonVO.success(dto);
    }
}

