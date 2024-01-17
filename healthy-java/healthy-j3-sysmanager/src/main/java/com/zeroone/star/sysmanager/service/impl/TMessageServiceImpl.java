package com.zeroone.star.sysmanager.service.impl;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageDTO;
import com.zeroone.star.project.dto.j3.message.SearchMessageDetailDTO;
import com.zeroone.star.sysmanager.entity.Message;
import com.zeroone.star.sysmanager.mapper.MessageMapper;
import com.zeroone.star.sysmanager.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

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

    /**
     * @description:消息详情业务
     * @author: 坚强少年
     * @date: 2024/1/17 17:05
     * @param: [detailDTO]
     * @return: com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.message.MessageDTO>
     **/
    @Override
    public PageDTO<SearchMessageDetailDTO> queryMessageDetail(PageDTO<MessageDTO> detailDTO) {
        //分页

        return null;
    }
}
