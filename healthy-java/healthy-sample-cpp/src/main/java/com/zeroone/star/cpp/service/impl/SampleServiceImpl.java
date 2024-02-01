package com.zeroone.star.cpp.service.impl;

import com.zeroone.star.cpp.service.ISampleService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;
import springfox.documentation.spring.web.json.Json;

import java.util.Map;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author TripleG
 * @since 2024-01-15
 */
@AllArgsConstructor // Lombok注解，它会生成一个包含所有参数的构造函数
public class SampleServiceImpl implements ISampleService {
    private final Throwable throwable;

    private <T>JsonVO<T> setMsg(JsonVO<T> vo) {
        if (throwable.getMessage() != null) {
            vo.setMessage(throwable.getMessage());
        }
        else {
            vo.setMessage(throwable.getClass().getSimpleName());
        }
        return vo;
    }
    @Override
    public JsonVO<PageDTO<SampleDTO>> get(Map<String, Object> condition) {
        return setMsg(JsonVO.fail(null));
    }

    @Override
    public JsonVO<Long> post(SampleDTO dto) {
        return setMsg(JsonVO.fail(null));
    }

    @Override
    public JsonVO<Long> put(SampleDTO dto) {
        return setMsg(JsonVO.fail(null));
    }

    @Override
    public JsonVO<Long> delete(Long id) {
        return setMsg(JsonVO.fail(null));
    }
}
