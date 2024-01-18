package com.zeroone.star.sysmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageDetailDTO;
import com.zeroone.star.sysmanager.entity.Message;
import com.zeroone.star.sysmanager.mapper.MessageMapper;
import com.zeroone.star.sysmanager.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

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
    private MessageMapper messageMapper;
    /**
     * @description:消息详情业务
     * @author: 坚强少年
     * @date: 2024/1/17 17:05
     * @param: [detailDTO]
     * @return: com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.message.MessageDTO>
     **/
    @Override
    public PageDTO<MessageDetailDTO> queryMessageDetail(MessageDetailDTO detailDTO) {
        //分页
        PageDTO<MessageDetailDTO> page = PageDTO.create(new Page<MessageDetailDTO>(detailDTO.getPageIndex(), detailDTO.getPageSize()));
        //判断是否有条件
        if (detailDTO.getUserId() != null) {
            LambdaQueryWrapper<MessageDetailDTO> lambdaQueryWrapper = new LambdaQueryWrapper();
            //TODO:我们的消息表中，没有userId这个字段，需要将当前页面组装成一个临时表 ，在临时表里面检索条件
            //TODO：我们的用户Id怎么传过来的？根据发送人的姓名去遍历查找用户表得出来的么？
            lambdaQueryWrapper.like(MessageDetailDTO::getUserId,detailDTO.getUserId());
        }
        return null;
    }
}
