package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.MessageDTO;

public interface MessageService {

    PageDTO<MessageDTO> queryMessageDetail(PageDTO<MessageDTO> detailDTO);
}
