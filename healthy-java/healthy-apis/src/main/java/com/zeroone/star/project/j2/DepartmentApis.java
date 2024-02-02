package com.zeroone.star.project.j2;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.j2.dto.DepartmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;

import java.util.Arrays;
import java.util.List;

public interface DepartmentApis {

    JsonVO<Integer> addDepartment(DepartmentDTO department);

    JsonVO<Integer> removeDepartment(String[] ids);

    JsonVO<Integer> modifyDepartment(DepartmentDTO department);

    /**
     * 根据ID查询部门列表
     * @param id 上级部门ID
     * @return 查询结果
     */
    JsonVO<List<DepartmentMenuVO>> getMenus(int id);

    /**
     * 获取指定部门详情
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<DepartmentDTO> queryAll(DepartmentQuery condition);
}