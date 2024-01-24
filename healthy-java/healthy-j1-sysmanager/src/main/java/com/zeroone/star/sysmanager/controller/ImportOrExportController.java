package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j1.dto.sysmanager.DepartmentManagementDTO;
import com.zeroone.star.project.j1.sysmanager.ImportOrExportApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-导入导出")
public class ImportOrExportController implements ImportOrExportApis {

    /**
     * 导出全部数据
     * @param departmentManagementDTO
     * @return
     */
    @ApiOperation("导出全部数据")
    @GetMapping("export-form-department")
    @Override
    public JsonVO exportFormOfDepartment(DepartmentManagementDTO departmentManagementDTO) {
        return JsonVO.success(null);
    }

    /**
     * 导入用户数据
     * @param file 用户数据文件
     * @return
     */
    @PostMapping("/import-user-data")
    @ApiOperation(value = "导入用户数据")
    @Override
    public JsonVO<String> importUserData(MultipartFile file) {
        return JsonVO.success("导入成功");
    }
}
