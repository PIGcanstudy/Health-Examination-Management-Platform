package com.zeroone.star.cpp.service;

import com.zeroone.star.cpp.config.FeignConfiguration;
import com.zeroone.star.cpp.fall.CppServiceFallBack;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

/**
 * <p>
 * 描述：声明式服务接口
 * </p>
 *
 * @author TripleG
 * @since 2024-01-20
 */
@FeignClient(
        name = "${cpp.sample.name}",
        url = "${cpp.sample.url}",
        fallbackFactory = CppServiceFallBack.class,
        configuration = FeignConfiguration.class
)
public interface ISampleService {
    @GetMapping("/sample")
    JsonVO<PageDTO<SampleDTO>> get(@RequestParam Map<String, Object> condition);
    @PostMapping("/sample")
    JsonVO<Long> post(@RequestBody SampleDTO dto);
    @PutMapping("/sample")
    JsonVO<Long> put(@RequestBody SampleDTO dto);
    @DeleteMapping("/sample/{id}")
    JsonVO<Long> delete(@PathVariable(name = "id") Long id);

}
