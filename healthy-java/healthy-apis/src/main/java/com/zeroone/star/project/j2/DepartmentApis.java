package com.zeroone.star.project.j2;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.j2.dto.DepartmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;

import java.util.Arrays;

public interface DepartmentApis {

    JsonVO<Integer> addDepartment(DepartmentDTO department) ;

    JsonVO<Integer> removeDepartment(String[] ids);

    JsonVO<Integer> modifyDepartment(DepartmentDTO department) ;
}
