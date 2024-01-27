package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.j3.typeLibrary.TypeLibDeleteDTO;
import cn.hutool.core.util.ObjectUtil;
import com.zeroone.star.project.dto.j3.typeLibrary.typeAddDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeLibraryTreeDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeUpdateDTO;
import com.zeroone.star.project.j3.sysconfig.SysConfigApis;
import com.zeroone.star.project.j3.typelib.TypeLibApis;
import com.zeroone.star.project.query.j3.TypeLibraryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeAddVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeUpdateVO;
import com.zeroone.star.sysmanager.service.ITProTypeService;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
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
    @Resource
    ITProTypeService typeService;

    /**
     * 获取类型树
     *
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
    public JsonVO<Integer> removeTypeLib(TypeLibDeleteDTO typeLibDeleteDTO) {
        return null;
    }

    @Override
    @PostMapping("/addType")
    public JsonVO<typeAddVO> addType(@RequestBody typeAddDTO typeadddto) {
        return JsonVO.success(typeService.addType(typeadddto));
    }

    @Override
    @PostMapping("/updateType")
    public JsonVO<Object> updateType(@RequestBody typeUpdateDTO typeupdatedto) {
        typeUpdateVO typeUpdateVO = typeService.updateType(typeupdatedto);
        if(ObjectUtil.isNotNull(typeUpdateVO)){
            return JsonVO.success(typeUpdateVO);
        }
        else{
            return JsonVO.fail("修改失败");
        }
    }
}
