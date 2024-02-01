package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @Description: 科室术语表的接口
 * @Author: Laputa
 * @CreateTime: 2024-01-30  01:06
 * @Version: 1.0
 */
public interface TOfficeTermApi {
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
