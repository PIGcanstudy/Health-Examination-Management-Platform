package com.zeroone.star.project.j4.terminologymanagement;

import com.sun.org.apache.xpath.internal.operations.Bool;
import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.time.temporal.TemporalQuery;

/**
 * @Description: 术语管理的接口
 * @Author: Laputa
 * @CreateTime: 2024-01-30  01:06
 * @Version: 1.0
 */
public interface TerminologymanagementApi {
    /**
     * @param query
     * @description: 启用/禁用术语
     * @author: Laputa
     * @date: 2024-01-30  1:57
     * @param:
     * @return:
     */
    JsonVO<Boolean> switchTerm(SwitchTermQuery query) throws Exception;
}
