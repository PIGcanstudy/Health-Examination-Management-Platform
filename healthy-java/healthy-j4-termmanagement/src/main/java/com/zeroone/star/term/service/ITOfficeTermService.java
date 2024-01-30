package com.zeroone.star.term.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.entity.TOfficeTerm;

/**
 * @author
 * 时间：2024.1.1
 * 功能：
 */
public interface ITOfficeTermService extends IService<TOfficeTerm> {

    /**
     * @Author: ayuan
     * @param: [termDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 更新术语
     **/
    JsonVO<ResultStatus> updateOfficeTerm(TermDTO termDTO);
}
