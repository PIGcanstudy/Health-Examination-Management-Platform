package com.zeroone.star.publish.comp;

import com.zeroone.star.project.dto.notify.SampleNotifyDTO;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：消息发布组件
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Component
public class RocketMQSourceComponent {
    @Resource
    Source source;

    public void publishNotify(SampleNotifyDTO notify) {
        source.output().send(MessageBuilder.withPayload(notify).build());
    }
}
