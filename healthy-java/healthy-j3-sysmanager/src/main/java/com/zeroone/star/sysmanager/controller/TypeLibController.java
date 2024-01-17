package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.j3.typeLibrary.TypeLibDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeLibraryTreeDTO;
import com.zeroone.star.project.j3.sysconfig.SysConfigApis;
import com.zeroone.star.project.j3.typelib.TypeLibApis;
import com.zeroone.star.project.query.j3.TypeLibraryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * 系统配置Controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:10
 **/
@RestController
@RequestMapping("/j3-typeLib")
@Api("类型库")
public class TypeLibController implements TypeLibApis {

    /**
     * 获取类型树
     * @param typeLibraryTreedto
     * @return
     */
    @Override
    public JsonVO<List<TProTypeVO>> getAllProTypeByTree(typeLibraryTreeDTO typeLibraryTreedto) {
        return null;
    }

    /**
     * 搜索类型列表
     * @param typeLibraryQuery
     * @return
     */
    @Override
    public JsonVO<List<TProTypeVO>> queryTProTypeListByPage(TypeLibraryQuery typeLibraryQuery) {
        return null;
    }

    @Override
    public JsonVO<Integer> removeTypeLib(TypeLibDTO typeLibDTO) {
        return null;
    }
}
