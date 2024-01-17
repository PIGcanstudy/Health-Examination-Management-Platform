package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j1.sysmanager.ModifyMailApis;
import com.zeroone.star.project.j1.vo.sysmanager.ModifyMailVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("user-data")
@Api(tags = "修改邮箱接口")
public class ModifyMailController implements ModifyMailApis {
    @ApiOperation("修改邮箱")
    @GetMapping("modefy-mail")
    @Override
    public JsonVO modifyMail(ModifyMailVO modifyMailVO) {
        return JsonVO.success(null);
    }
}
