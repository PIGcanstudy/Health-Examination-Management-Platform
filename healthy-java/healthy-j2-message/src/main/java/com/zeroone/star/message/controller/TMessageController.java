package com.zeroone.star.message.controller;


import com.zeroone.star.project.j2.MessageApis;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 消息 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Api(tags = "消息")
@RestController
@RequestMapping("/message/t-message")
public class TMessageController implements MessageApis {
    @ApiOperation(value = "删除消息")
    @DeleteMapping("remove-by-ids")
    @Override
    public JsonVO<Object> removeMessage(@RequestParam String[] ids) {
        return null;
    }
    @ApiOperation(value = "刷新系统公告")
    @GetMapping("query-by-id")
    @Override
    public JsonVO<MessageDTO> queryMessage(@RequestParam String id) {
        return null;
    }
}

