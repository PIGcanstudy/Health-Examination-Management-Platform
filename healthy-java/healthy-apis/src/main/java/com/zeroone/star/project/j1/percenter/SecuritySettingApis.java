package com.zeroone.star.project.j1.percenter;

import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 个人中心-安全设置相关接口
 */
public interface SecuritySettingApis {
    /**
     * 修改密码接口
     *
     * @param modifyPasswordVO 修改密码视图对象
     * @return 修改结果
     */
     JsonVO<String> changePassword(ModifyPasswordDTO modifyPasswordVO);

    /**
     * 修改手机接口
     *
     * @param modifyPhoneVO 修改手机号视图对象
     * @return 修改结果
     */
    JsonVO<String> changePhone(ModifyPhoneDTO modifyPhoneVO);
}
