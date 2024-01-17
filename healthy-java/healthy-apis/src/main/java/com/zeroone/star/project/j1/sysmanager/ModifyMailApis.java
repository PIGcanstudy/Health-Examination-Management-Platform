package com.zeroone.star.project.j1.sysmanager;

import com.zeroone.star.project.j1.vo.sysmanager.ModifyMailVO;
import com.zeroone.star.project.vo.JsonVO;


public interface ModifyMailApis {
    /**
     * 系统管理-用户管理，用户邮箱修改相关接口（修改用户邮箱）
     */
    JsonVO modifyMail(ModifyMailVO modifyMailVO);
}
