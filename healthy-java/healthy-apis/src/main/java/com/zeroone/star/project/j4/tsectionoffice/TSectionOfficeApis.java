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
    /**
     * @Author: ayuan
     * @param: [TSectionOfficeDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 新增科室
     **/
    JsonVO<ResultStatus> addSectionOffice(@Validated TSectionOfficeDTO TSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [TSectionOfficeDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 修改科室
     **/
    JsonVO<ResultStatus> modifySectionOffice(@Validated TSectionOfficeDTO TSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [ids]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 删除科室
     **/
    JsonVO<ResultStatus> removeSectionOffice(@NotNull(message = "List不能为空") List<String> ids);
}
