package com.zeroone.star.terminologymanagement.controller;


import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.project.j4.terminologymanagement.TerminologymanagementApi;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.terminologymanagement.service.ITOfficeTermService;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 科室术语表 前端控制器
 * </p>
 *
 * @author Laputa
 * @since 2024-01-30
 */
@RestController
@RequestMapping("/terminologymanagement")
public class TOfficeTermController implements TerminologymanagementApi {

    @Autowired
    private ITOfficeTermService termService;

    @ApiOperation(value = "启用/禁止术语")
    @PostMapping("switch-term")
    @Override
    public JsonVO<Boolean> switchTerm(SwitchTermQuery query) throws Exception {
        if (query == null) {
            throw new RuntimeException("请求参数不能为空");
        }
        Boolean b = termService.switchTerm(query);
        if (b != true) {
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }
}

