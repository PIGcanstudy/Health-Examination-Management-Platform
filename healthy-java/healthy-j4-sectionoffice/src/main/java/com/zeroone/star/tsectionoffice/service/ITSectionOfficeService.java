package com.zeroone.star.tsectionoffice.service;

import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
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
    void saveSectionOffice(TSectionOfficeDTO tSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: void
     * @Description: 修改科室
     **/
    void updateSectionOffice(TSectionOfficeDTO tSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [ids]
     * @return: void
     * @Description: 删除科室
     **/
    void removeSectionOffice(List<String> ids);
}
