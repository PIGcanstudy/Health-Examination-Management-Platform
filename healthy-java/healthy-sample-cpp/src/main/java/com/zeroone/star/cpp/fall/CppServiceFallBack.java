package com.zeroone.star.cpp.fall;

import com.zeroone.star.cpp.service.impl.SampleServiceImpl;
import feign.hystrix.FallbackFactory;
import org.springframework.stereotype.Component;

/**
 * <p>
 * 描述：声明式服务器异常工厂实现
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Component
public class CppServiceFallBack implements FallbackFactory<SampleServiceImpl> {
    @Override
    public SampleServiceImpl create(Throwable throwable) {
        return new SampleServiceImpl(throwable);
    }
}
