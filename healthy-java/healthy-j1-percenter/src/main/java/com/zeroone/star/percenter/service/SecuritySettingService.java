package com.zeroone.star.percenter.service;

import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;



public interface SecuritySettingService {
    void changePassword(ModifyPasswordDTO modifyPasswordDTO) throws Exception;
    void changePhone(ModifyPhoneDTO modifyPhoneDTO) throws Exception;

}