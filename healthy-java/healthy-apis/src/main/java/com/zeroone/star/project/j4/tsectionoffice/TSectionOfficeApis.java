package com.zeroone.star.project.j4.tsectionoffice;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
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

    /**
     * 根据条件查询科室列表(分页+条件)
     *
     * @param getSectionOfficeQuery 封装请求体参数
     * @return 封装的统一响应模型
     */

    JsonVO<PageDTO<GetSectionOfficeVO>> queryAllSectionOffice(GetSectionOfficeQuery getSectionOfficeQuery);

    JsonVO<List<GetSecNameVO>> GetAllSecName(GetSecNameDTO getSecNameDTO);

    JsonVO<List<GetSectionOfficeVO>> GetAllSectionOffice(GetSectionOfficetDTO getSectionOfficetDTO);



}
