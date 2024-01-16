package com.zeroone.star.tsectionoffice.controller;

import com.zeroone.star.project.j4.tsectionoffice.TSectionOfficeApis;
import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.tsectionoffice.service.ITSectionOfficeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author AYuan
 * @since 2024-01-16
 */
@RestController
@Api(tags = "科室管理接口")
@RequestMapping("/sectionOffice/t-section-office")
public class TSectionOfficeController implements TSectionOfficeApis {

    @Resource
    private ITSectionOfficeService itSectionOfficeService;


    @PostMapping("add-section-office")
    @ApiOperation("新增科室")
    @Override
    public JsonVO<ResultStatus> addSectionOffice(@RequestBody TSectionOfficeDTO tSectionOfficeDTO) {
        itSectionOfficeService.saveSectionOffice(tSectionOfficeDTO);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @PutMapping("modify-section-office")
    @ApiOperation("修改科室")
    @Override
    public JsonVO<ResultStatus> modifySectionOffice(@RequestBody TSectionOfficeDTO tSectionOfficeDTO) {
        itSectionOfficeService.updateSectionOffice(tSectionOfficeDTO);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @DeleteMapping("remove-section-office")
    @ApiOperation("删除科室")
    @Override
    public JsonVO<ResultStatus> removeSectionOffice(@RequestParam List<String> ids) {
        itSectionOfficeService.removeSectionOffice(ids);
        return JsonVO.success(ResultStatus.SUCCESS);
    }
}

