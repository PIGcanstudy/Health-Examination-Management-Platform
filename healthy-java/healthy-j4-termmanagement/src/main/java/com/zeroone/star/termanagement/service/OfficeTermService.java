package com.zeroone.star.termanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j4.dto.UpdateTermanagementDTO;
import com.zeroone.star.termanagement.entity.OfficeTermEntity;


/**
 * 科室术语表(OfficeTerm)表服务接口
 *
 * @author makejava
 * @since 2024-01-30 14:43:18
 */
public interface OfficeTermService extends IService<OfficeTermEntity> {
    /**
     * 删除术语
     * @param office_id
     */
    void deletetermanagement(Integer office_id);
}
