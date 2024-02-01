package com.zeroone.star.publish.controller;

import com.zeroone.star.project.dto.notify.SampleNotifyDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.publish.comp.RocketMQSourceComponent;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 测试消息发送控制器
 * </p>
 *
 * @author TripleG
 * @since 2024-01-15
 */
@RestController
@RequestMapping("publish")
@Api(tags = "publish")
public class SampleController {
    @Resource
    RocketMQSourceComponent mq;

    @PostMapping("add-notify")
    @ApiOperation(value = "新增通知")
    public JsonVO<Boolean> addData(SampleNotifyDTO dto) {
        mq.publishNotify(dto);
        return JsonVO.success(true);
    }
}
