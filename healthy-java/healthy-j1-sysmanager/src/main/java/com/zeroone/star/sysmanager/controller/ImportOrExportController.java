package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j1.dto.sysmanager.DepartmentManagementDTO;
import com.zeroone.star.project.j1.sysmanager.ImportOrExportApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-导入导出")
public class ImportOrExportController implements ImportOrExportApis {

    @ApiOperation("导出科室管理表单")
    @GetMapping("export-form-department")
    @Override
    public JsonVO exportFormOfDepartment(DepartmentManagementDTO departmentManagementDTO) {
        return JsonVO.success(null);
    }
}
