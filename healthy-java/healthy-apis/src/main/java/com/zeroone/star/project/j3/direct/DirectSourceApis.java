package com.zeroone.star.project.j3.direct;

import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @description: 字典数据api
 * @author: 坚强少年
 * @date: 2024/1/15 20:34
 **/
public interface DirectSourceApis {

    /**
     * 通过id删除数据字典，支持批量删除
     * @auther chenxiaxin
     * @param ids
     * @return
     */
    JsonVO<Boolean> deleteByIds(String[] ids);

    /**
     * 通过前端传递过来的数据，查询符合条件的工种名称列表
     * @auther chenxiaxin
     * @param wordTypeListQuery
     * @return
     */
    JsonVO<List<WordTypeListQuery>> queryByWordType(WordTypeListQuery wordTypeListQuery);
}
