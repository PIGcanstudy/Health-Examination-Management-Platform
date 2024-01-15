package com.zeroone.star.message.service.impl;

import com.zeroone.star.message.entity.TMessageSend;
import com.zeroone.star.message.mapper.TMessageSendMapper;
import com.zeroone.star.message.service.ITMessageSendService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 消息发送 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Service
public class TMessageSendServiceImpl extends ServiceImpl<TMessageSendMapper, TMessageSend> implements ITMessageSendService {

}
