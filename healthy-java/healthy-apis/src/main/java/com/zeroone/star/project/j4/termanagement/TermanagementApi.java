package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface TermanagementApi {
    /**
     * 删除术语
     * @param ids
     * @return
     */
    JsonVO<Boolean> deletetermanagement(List<String> ids);
}
