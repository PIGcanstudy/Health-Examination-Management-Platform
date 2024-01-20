package com.zeroone.star.project.j1.percenter;

import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.vo.percenter.ModifyPasswordVO;
import com.zeroone.star.project.j1.vo.percenter.ModifyPhoneVO;
import com.zeroone.star.project.j1.vo.sysmanager.ModifyMailVO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 个人中心-安全设置相关接口
 */
public interface SecuritySettingApis {
    /**
     *  修改密码接口
     *
     * @param modifyPasswordVO 修改密码视图对象
     * @return 修改结果
     */
     JsonVO<ModifyPasswordDTO> changePassword(ModifyPasswordVO modifyPasswordVO);

    /**
     *  修改手机接口
     *
     * @param modifyPhoneVO 修改手机号视图对象
     * @return 修改结果
     */
    JsonVO<ModifyPhoneDTO> changePhone(ModifyPhoneVO modifyPhoneVO);

    /**
     * 系统管理-用户管理，用户邮箱修改相关接口（修改用户邮箱）
     *
     */
    JsonVO modifyMail(ModifyMailVO modifyMailVO);
}
