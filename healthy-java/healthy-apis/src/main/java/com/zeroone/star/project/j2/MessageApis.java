package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface MessageApis {

    JsonVO<Object> removeMessage(String[] ids);
}
