package com.zeroone.star.portfolioitems.controller;


import com.zeroone.star.portfolioitems.service.ITPortfolioProjectService;
import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.portfolioitems.PortfolioProjectApi;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 组合项目 前端控制器
 * </p>
 *
 * @author Laputa
 * @since 2024-01-24
 */
@RestController
@RequestMapping("/portfolioitems/")
public class TPortfolioProjectController implements PortfolioProjectApi {

    @Autowired
    private ITPortfolioProjectService itPortfolioProjectService;

    @ApiOperation(value = "组合项目的详情信息")
    @GetMapping("/{id}")
    @Override
    public JsonVO<PortfolioItemDTO> getPortfolioItem(@PathVariable String id) throws Exception {
        if (id == null) {
            throw new RuntimeException("id不能为空");
        }
        PortfolioItemDTO portfolioItemDTO =  itPortfolioProjectService.getPortfolioItemById(id);
        return JsonVO.success(portfolioItemDTO);
    }


}

