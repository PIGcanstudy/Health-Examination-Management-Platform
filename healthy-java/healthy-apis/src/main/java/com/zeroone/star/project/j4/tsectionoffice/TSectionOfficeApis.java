package com.zeroone.star.project.j4.tsectionoffice;

import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.validation.annotation.Validated;

import javax.validation.Valid;
import javax.validation.constraints.NotNull;
import java.util.List;

/**
 * @BelongsProject: healthy-java
 * @BelongsPackage: com.zeroone.star.project.j4.departmentmanagement
 * @Author: ayuan
 * @CreateTime: 2024-01-16
 * @Description:
 */
public interface TSectionOfficeApis {
    JsonVO<ResultStatus> addSectionOffice(@Validated TSectionOfficeDTO TSectionOfficeDTO);
    JsonVO<ResultStatus> modifySectionOffice(@Validated TSectionOfficeDTO TSectionOfficeDTO);
    JsonVO<ResultStatus> removeSectionOffice(@NotNull(message = "List不能为空") List<String> ids);
}
