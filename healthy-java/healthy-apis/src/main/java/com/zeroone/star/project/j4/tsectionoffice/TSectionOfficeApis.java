package com.zeroone.star.project.j4.tsectionoffice;

import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import java.util.List;

/**
 * @BelongsProject: healthy-java
 * @BelongsPackage: com.zeroone.star.project.j4.departmentmanagement
 * @Author: ayuan
 * @CreateTime: 2024-01-16
 * @Description:
 */
public interface TSectionOfficeApis {
    // JsonVO<PageDTO<SectionOfficeDTO>> querySectionOffice(SectionOfficeQuery sectionOfficeQuery);
    JsonVO<ResultStatus> addSectionOffice(TSectionOfficeDTO TSectionOfficeDTO);
    JsonVO<ResultStatus> modifySectionOffice(TSectionOfficeDTO TSectionOfficeDTO);
    JsonVO<ResultStatus> removeSectionOffice(List<String> ids);
}
