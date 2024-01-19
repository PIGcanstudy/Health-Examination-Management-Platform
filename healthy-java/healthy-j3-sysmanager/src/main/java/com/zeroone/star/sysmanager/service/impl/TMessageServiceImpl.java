package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.core.bean.BeanUtil;
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
        //先去redis缓存中查询

        //查询到直接返回结果(同时校验过期时间)

        //如果过期需要从数据库当中读取数据回写到redis中

        //从数据库读取数据：
        //判断是否有条件
/*        if (detailDTO.getUserId() != null) {*/
             //有条件，条件查询
            //TODO:我们的消息表中，没有userId这个字段，需要将当前页面组装成一个临时表 ，在临时表里面检索条件
            /*LambdaQueryWrapper<MessageDetailDTO> wrapper = new LambdaQueryWrapper<>();
            wrapper.like(MessageDetailDTO::getUserId,detailDTO.getUserId());*/
        LambdaQueryWrapper<Message> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(Message::getId,detailDTO.getId());
        List<Message> message = messageMapper.selectList(wrapper);

            //将查询到的数据进行分页
            PageDTO<MessageDetailDTO> page = PageDTO.create(new Page<>(detailDTO.getPageIndex(), detailDTO.getPageSize()), MessageDetailDTO.class);
        List<MessageDetailDTO> messageDetailDTOS = BeanUtil.copyToList(message, MessageDetailDTO.class);
        page.setRows(messageDetailDTOS);

            return page;
       /* }else {
            //没有条件，分页
            PageDTO<MessageDetailDTO> page = PageDTO.create(new Page<>(detailDTO.getPageIndex(), detailDTO.getPageSize()), MessageDetailDTO.class);
            //根据消息Id查询数据

            return page;
        }*/
    }
}
