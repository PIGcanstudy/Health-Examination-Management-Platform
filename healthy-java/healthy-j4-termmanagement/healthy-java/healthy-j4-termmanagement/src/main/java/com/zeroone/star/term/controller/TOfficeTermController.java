package com.zeroone.star.term.controller;


import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.j4.tofficeterm.TermApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.service.ITOfficeTermService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;


@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
@Validated
public class TOfficeTermController implements TermApis {
    @Resource
    private ITOfficeTermService itOfficeTermService;

    @Override
    @ApiOperation("更新术语")
    @PostMapping("/modify-term")
    public JsonVO<ResultStatus> modifyOfficeTerm(@Validated @RequestBody TermDTO termDTO) {
        return itOfficeTermService.updateOfficeTerm(termDTO);
    }
}


