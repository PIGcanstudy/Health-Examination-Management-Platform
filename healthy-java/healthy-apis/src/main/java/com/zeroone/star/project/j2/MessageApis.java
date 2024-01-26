package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface MessageApis {

    JsonVO<PageDTO<MessageDTO>> queryMessageAll(MessageQuery messageQuery);

    JsonVO<Object> removeMessage(String[] ids);

    JsonVO<MessageDTO> queryMessage(String id);
}
