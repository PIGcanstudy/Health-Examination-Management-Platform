package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.MessageDTO;
import com.zeroone.star.sysmanager.service.MessageService;
import org.springframework.stereotype.Service;

/**
 * @author 坚强少年
 * @date 2024/01/16 10:43
 **/
@Service
public class MessageServiceImpl extends ServiceImpl implements MessageService {
    @Override
    public PageDTO<MessageDTO> queryMessageDetail(PageDTO<MessageDTO> detailDTO) {
        //使用页面插件实现分页
        Page page = new Page(detailDTO.getPageIndex(),detailDTO.getPageSize());
        //条件查询
        /*? 点击消息详情页的时候，将消息数据传入，但是数据中不包含userId，
        * 只包含username*/
        return null;
    }
}
