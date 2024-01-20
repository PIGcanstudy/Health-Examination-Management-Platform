package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.sysmanager.entity.Message;
import com.zeroone.star.sysmanager.entity.MessageSend;
import com.zeroone.star.sysmanager.mapper.MessageMapper;
import com.zeroone.star.sysmanager.mapper.MessageSendMapper;
import com.zeroone.star.sysmanager.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 消息 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TMessageServiceImpl extends ServiceImpl<MessageMapper, Message> implements ITMessageService {

    @Resource
    private MessageSendMapper messageSendMapper;
    /**
     * @description:消息详情业务
     * @author: 坚强少年
     * @date: 2024/1/17 17:05
     * @param: [detailDTO]
     * @return: com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.message.MessageDTO>
     **/
    @Override
    public PageDTO<MessageResponseDTO> selectMessageDetailPage(MessageSendDTO messageSend) {
        Page page = new Page(messageSend.getPageIndex(),messageSend.getPageSize());
        LambdaQueryWrapper<MessageSend> wrapper = new LambdaQueryWrapper<>();
        if (messageSend.getUserId() != null){
            wrapper.eq(MessageSend::getUserId,messageSend.getUserId());
        }
        page = messageSendMapper.selectPage(page, wrapper);
        PageDTO<MessageResponseDTO> message = PageDTO.create(page);
        return message;
    }
}
