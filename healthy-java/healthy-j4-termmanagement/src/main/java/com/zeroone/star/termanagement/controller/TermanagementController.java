package com.zeroone.star.termanagement.controller;

import com.zeroone.star.project.j4.Termanagement.TermanagementApi;
import com.zeroone.star.project.j4.dto.UpdateTermanagementDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.termanagement.service.OfficeTermService;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;

public class TermanagementController implements TermanagementApi {
    @Autowired
    private OfficeTermService officeTermService;

    @Override
    @DeleteMapping("delete-termanagement")
    @ApiOperation(value = "删除术语")
    public JsonVO<Void> deletetermanagement(Integer office_id) {
        officeTermService.deletetermanagement(office_id);
        return JsonVO.success(null);
    }
}
