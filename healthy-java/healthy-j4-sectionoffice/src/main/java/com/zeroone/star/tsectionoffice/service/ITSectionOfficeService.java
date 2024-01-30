package com.zeroone.star.tsectionoffice.service;

import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.tsectionoffice.entity.TSectionOffice;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author AYuan
 * @since 2024-01-16
 */
public interface ITSectionOfficeService extends IService<TSectionOffice> {

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: void
     * @Description: 插入科室
     **/
    JsonVO<ResultStatus> saveSectionOffice(TSectionOfficeDTO tSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: void
     * @Description: 修改科室
     **/
    JsonVO<ResultStatus> updateSectionOffice(TSectionOfficeDTO tSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [ids]
     * @return: void
     * @Description: 删除科室
     **/
    JsonVO<ResultStatus> removeSectionOffice(List<String> ids);
}
