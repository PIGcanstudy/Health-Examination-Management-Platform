package com.zeroone.star.term.controller;

import com.zeroone.star.project.j4.termanagement.TermanagementApi;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.term.service.OfficeTermService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
@Validated
public class TermanagementController implements TermanagementApi {
    @Autowired
    private OfficeTermService officeTermService;

    @Override
    @DeleteMapping("delete-termanagement")
    @ApiOperation(value = "删除术语")
    public JsonVO<Boolean> deletetermanagement(List<String> ids) {
        return JsonVO.success(officeTermService.deletetermanagement(ids));
    }
}
