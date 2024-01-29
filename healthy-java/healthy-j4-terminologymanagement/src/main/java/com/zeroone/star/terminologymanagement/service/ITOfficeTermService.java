package com.zeroone.star.terminologymanagement.service;

import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.terminologymanagement.entity.TOfficeTerm;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 科室术语表 服务类
 * </p>
 *
 * @author Laputa
 * @since 2024-01-30
 */
public interface ITOfficeTermService extends IService<TOfficeTerm> {
    Boolean switchTerm(SwitchTermQuery query) throws Exception;
}
