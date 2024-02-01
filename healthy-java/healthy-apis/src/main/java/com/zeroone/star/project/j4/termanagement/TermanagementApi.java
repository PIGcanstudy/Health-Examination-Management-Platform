package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.vo.JsonVO;

public interface TermanagementApi {
    /**
     * 删除术语
     * @param office_id
     * @return
     */
    JsonVO<Void> deletetermanagement(Integer office_id);
}
