package com.zeroone.star.project.j4.template;

import com.zeroone.star.project.j4.dto.TemplateDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

public interface TemplateApis {

    public JsonVO<ResultStatus> addTemplate(TemplateDto templateDto);

    public JsonVO<TemplateDto> queryTermDetail(Long termId);
}
