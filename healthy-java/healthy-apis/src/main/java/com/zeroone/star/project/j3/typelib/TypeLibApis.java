package com.zeroone.star.project.j3.typelib;

import com.zeroone.star.project.dto.j3.typeLibrary.TypeLibDeleteDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeLibraryTreeDTO;
import com.zeroone.star.project.query.j3.TypeLibraryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;

import java.util.List;

/**
 * @description:类型库api
 * @author: 坚强少年
 * @date: 2024/1/15 20:36
 **/
public interface TypeLibApis {
    /**
     * 获取类型树
     * @param typeLibraryTreedto
     * @return
     */
    JsonVO<List<TProTypeVO>> getAllProTypeByTree(typeLibraryTreeDTO typeLibraryTreedto);

    /**
     * 搜索类型列表
     * @param typeLibraryQuery
     * @return
     */
    JsonVO<List<TProTypeVO>> queryTProTypeListByPage(TypeLibraryQuery typeLibraryQuery);


    /**
     *@Description: 批量删除类型库
     *@Param: [typeLibDTO]
     *@return:com.zeroone.star.project.vo.JsonVO<java.lang.Integer>
     *@Author: Mr.Lin
     *@Date: 2024/1/17 13:07
     */
    JsonVO<Integer> removeTypeLib(TypeLibDeleteDTO typeLibDeleteDTO);
}
