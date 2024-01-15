package com.zeroone.star.sample.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.sample.entity.Sample;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author TripleG
 * @since 2024-01-15
 */
public interface ISampleService extends IService<Sample> {
    /**
     * 分页查询所有数据
     * @param query 分页条件
     * @return 查询结果
     */
    PageDTO<SampleDTO> listPage(SampleQuery query);

    /**
     * 通过ID查询数据
     * @param id 唯一ID
     * @return 查询结果，如果没有返回null
     */
    SampleDTO getById(int id);
}
