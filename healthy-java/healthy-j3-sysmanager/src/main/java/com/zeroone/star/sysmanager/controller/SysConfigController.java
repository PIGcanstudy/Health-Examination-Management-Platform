package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.j3.system.SystemNoticeDTO;
import com.zeroone.star.project.j3.sysconfig.SysConfigApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.sysConfig.TSettingVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * 系统配置Controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:10
 **/
@RestController
@RequestMapping("/j3-sysConfig")
@Api("系统配置")
public class SysConfigController implements SysConfigApis {
    @ApiOperation("新增公告")
    @PostMapping("/addSystemNotice")
    @Override
    public JsonVO<SystemNoticeDTO> addSystemNotice(SystemNoticeDTO systemNoticeDTO) {
        JsonVO<SystemNoticeDTO> jsonVO = new JsonVO<>();
        jsonVO.setCode(200);
        jsonVO.setMessage("插入成功");
        jsonVO.setData(systemNoticeDTO);
        return jsonVO;
    }

    @ApiOperation("修改公告")
    @PostMapping("/modifySystemNotice")
    @Override
    public JsonVO<SystemNoticeDTO> modifySystemNotice(SystemNoticeDTO systemNoticeDTO) {
        return null;
    }

    @ApiOperation("获取公告")
    @PostMapping("/querySystemNotice")
    @Override
    public JsonVO<TSettingVO> querySystemNotice() {
        return null;
    }
}
