package com.zeroone.star.portfolioitems.controller;


import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.portfolioitems.PortfolioProjectApi;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
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
    @ApiOperation(value = "组合项目的详情信息")
    @GetMapping("get-portfolioitems")
    @Override
    public JsonVO<PortfolioItemDTO> getProtfolioItem(@RequestParam(value = "id", required = true) Integer id) throws Exception {

        if (dto.getIds().size() == 0) {
            throw new RuntimeException("消息id列表不能为空");
        }
        Boolean b = messageService.markReadMessage(dto);
        if (b == true) {
            return JsonVO.success(true);
        } else {
            return JsonVO.fail(false);
        }
    }
}

