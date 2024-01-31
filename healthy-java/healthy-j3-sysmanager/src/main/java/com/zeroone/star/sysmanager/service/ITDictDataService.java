package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j3.dictdata.AddDictDataDTO;
import com.zeroone.star.project.dto.j3.dictdata.ModifyDictData;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.DictData;

/**
 * <p>
 * 字典数据 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITDictDataService extends IService<DictData> {
    JsonVO<Boolean> AddDictData(AddDictDataDTO addDictDataDTO);

    JsonVO<Boolean> ModifyDictData(ModifyDictData modifyDictData);
}
