package com.zeroone.star.percenter.controller;

import com.zeroone.star.project.j1.dto.percenter.ModifyPersonalInfoDTO;
import com.zeroone.star.project.j1.percenter.BaseInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/base-info")
@Api(tags = "基本信息")
public class BaseInfoController implements BaseInfoApis {
    /**
     * 修改个人基础信息
     * @param modifyPersonalInfoDTO 可修改的个人基础信息
     * @return
     */
    @Override
    @PostMapping("/modify-personal-info")
    @ApiModelProperty("修改个人基础信息")
    public JsonVO<String> modifyPersonalInfo(@RequestBody ModifyPersonalInfoDTO modifyPersonalInfoDTO) {
        return JsonVO.success("修改成功");
    }
}
