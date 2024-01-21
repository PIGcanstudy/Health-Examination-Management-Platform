package com.zeroone.star.project.j3.direct;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.dictdata.AddDictDataDTO;
import com.zeroone.star.project.j3.dto.dictdata.UpdateDictDataDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface DirectSourceApis {
    JsonVO<PageDTO<UpdateDictDataDTO>> UpdateDictData();

    JsonVO<PageDTO<AddDictDataDTO>> AddDictData();
}
