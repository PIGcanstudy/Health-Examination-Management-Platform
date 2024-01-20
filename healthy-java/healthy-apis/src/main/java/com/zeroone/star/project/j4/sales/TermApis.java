package com.zeroone.star.project.j4.sales;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDto;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
public interface TermApis {
    /**
     * 术语列表查询接口
     * @param query 查询条件
     * @return 查询结果
     */
     JsonVO<PageDTO<TermDto>> queryTermList(TermQuery query) ;
    JsonVO<PageDTO<TermDto>> queryTermnameList(TermQuery query) ;
    JsonVO<TermDto> queryTermDetail( Long termId);

}
