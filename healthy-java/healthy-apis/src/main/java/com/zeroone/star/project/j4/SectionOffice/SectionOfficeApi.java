package com.zeroone.star.project.j4.SectionOffice;

import com.zeroone.star.project.j4.dto.PageDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.project.vo.JsonVO;

public interface SectionOfficeApi {
    /**
     * 根据条件查询科室列表(分页+条件)
     * @param getSectionOfficeQuery  封装请求体参数
     * @return  封装的统一响应模型
     */
    JsonVO<PageDTO<GetSectionOfficeVO>> queryAllSectionOffice(GetSectionOfficeQuery getSectionOfficeQuery);
}
