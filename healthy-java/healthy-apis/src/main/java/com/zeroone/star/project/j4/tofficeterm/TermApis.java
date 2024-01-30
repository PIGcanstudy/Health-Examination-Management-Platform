package com.zeroone.star.project.j4.tofficeterm;

import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;

/**
 * @BelongsProject: healthy-java
 * @BelongsPackage: com.zeroone.star.project.j4.tofficeterm
 * @Author: ayuan
 * @CreateTime: 2024-01-28
 * @Description:
 */
public interface TermApis {
    /**
     * @Author: ayuan
     * @param: [termDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 更新术语
     **/
    JsonVO<ResultStatus> modifyOfficeTerm(@Validated TermDTO termDTO);
}
