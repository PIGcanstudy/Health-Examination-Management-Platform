package com.zeroone.star.departmanagement.controller;

import com.zeroone.star.departmanagement.service.SectionOfficeService;
import com.zeroone.star.project.j4.SectionOffice.SectionOfficeApi;
import com.zeroone.star.project.j4.dto.PageDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * (SectionOffice)表控制层
 *
 * @author makejava
 * @since 2024-01-17 21:52:28
 */
@RestController
@RequestMapping("/section/section-office")
@Api(tags = "科室管理")
public class SectionOfficeController implements SectionOfficeApi {


    @Override
    @GetMapping("query-allsection-office")
    @ApiOperation(value = "获取科室列表（分页+条件）")
    public JsonVO<PageDTO<GetSectionOfficeVO>> queryAllSectionOffice(GetSectionOfficeQuery getSectionOfficeQuery) {
//        return JsonVO.success(SectionOfficeService.listAllSectionOffice(getSectionOfficeQuery));
        return null;
    }

}

