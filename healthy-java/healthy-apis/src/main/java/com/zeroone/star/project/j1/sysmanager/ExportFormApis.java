package com.zeroone.star.project.j1.sysmanager;

import com.zeroone.star.project.j1.dto.sysmanager.DepartmentManagementDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface ExportFormApis {
    /**
     * 个人中心-科室管理，导出本页数据
     */
    JsonVO exportFormOfDepartment(DepartmentManagementDTO departmentManagementDTO);
}
