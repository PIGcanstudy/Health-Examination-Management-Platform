package com.zeroone.star.termmanagement.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.termmanagement.entity.Term;

import java.util.List;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
public interface TermService extends IService<Term> {
    /**
     * 分页查询所有数据
     * @param query 分页条件
     * @return 查询结果
     */
    PageDTO<TermDto> queryTermList(TermQuery query);
    /**
     * 通过ID查询数据
     * @param id 唯一ID
     * @return 查询结果，如果没有查询到返回null
     */
//    TermDto getById(int id);

    PageDTO<TermDto> queryTermnameList(TermQuery query);
    TermDto queryTermDetail(long id);
}
