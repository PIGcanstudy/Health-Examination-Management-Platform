package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @Author：宵夜
 * @Description:
 * @Date：2024/1/17 9:45
 */
public interface RoleApis {

    JsonVO<MessageDTO> roleDTO(RoleDTO roleDTO);


}
