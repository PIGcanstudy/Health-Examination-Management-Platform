package com.zeroone.star.project.j1.percenter;

import com.zeroone.star.project.j1.dto.percenter.GetSmsCodeDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyEmailDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.vo.percenter.ModifyEmailVO;
import com.zeroone.star.project.j1.vo.percenter.ModifyPasswordVO;
import com.zeroone.star.project.j1.vo.percenter.ModifyPhoneVO;
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
     *  修改邮箱接口
     * @param modifyEmailVO 修改邮箱视图对象
     * @return
     */
    JsonVO<ModifyEmailDTO> changeEmail(ModifyEmailVO modifyEmailVO);

    /**
     * 获取短信验证码
     * @param modifyPhoneVO
     * @return
     */
    JsonVO<GetSmsCodeDTO> getSmsCode(ModifyPhoneVO modifyPhoneVO);
}
