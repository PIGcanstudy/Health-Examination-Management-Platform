package com.zeroone.star.departmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.departmanagement.entity.SectionOffice;


/**
 * (SectionOffice)表服务接口
 *
 * @author makejava
 * @since 2024-01-17 21:52:31
 */
public interface SectionOfficeService extends IService<SectionOffice> {

    Object update(SectionOffice sectionOffice);

    Object deleteById(String id);
}
