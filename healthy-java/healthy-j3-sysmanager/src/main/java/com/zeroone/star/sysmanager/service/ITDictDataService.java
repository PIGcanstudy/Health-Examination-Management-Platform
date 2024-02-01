package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dict.WordTypeListDTO;
import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.sysmanager.entity.DictData;

import java.util.List;

/**
 * <p>
 * 字典数据 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITDictDataService extends IService<DictData> {
    /**
     * 通过ID查询数据
     * @param id 唯一ID
     * @return 查询结果，如果没有查询到返回null
     */
    DictData getById(String id);

    /**
     * 通过id删除数据
     * @param id
     */
    void removeById(String id);

    /**
     * 分页查询所有数据
     * @param wordTypeListQuery 分页条件
     * @return
     */
    PageDTO<WordTypeListDTO> listPage(WordTypeListQuery wordTypeListQuery);

}
