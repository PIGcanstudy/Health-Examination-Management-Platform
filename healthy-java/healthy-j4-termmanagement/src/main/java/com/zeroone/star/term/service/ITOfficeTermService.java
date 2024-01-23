package com.zeroone.star.term.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.term.entity.TOfficeTerm;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
public interface ITOfficeTermService extends IService<TOfficeTerm> {

    /**
     * 分页查询所有数据
     * @param query 分页条件
     * @return 查询结果
     */
    PageDTO<TermDto> queryTermList(TermQuery query);
    PageDTO<TermDto> queryTermnameList(TermNameQuery nameQuery);
    TermDto queryTermDetail( String id);


}
