package com.zeroone.star.message.service.impl;

import com.zeroone.star.message.entity.TMessage;
import com.zeroone.star.message.mapper.TMessageMapper;
import com.zeroone.star.message.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 消息 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Service
public class TMessageServiceImpl extends ServiceImpl<TMessageMapper, TMessage> implements ITMessageService {

}
