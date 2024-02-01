package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dictdata.DictDataDTO;
import com.zeroone.star.project.query.j3.DictData.DictDataQuery;
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
     * 获取字典数据名称
     * @return
     */
    List<String> getDictDataTitle();

    /**
     * 根据条件及分页获取字典数据列表
     * @param query
     * @return
     */
    PageDTO<DictDataDTO> ListPage(DictDataQuery query);

}
