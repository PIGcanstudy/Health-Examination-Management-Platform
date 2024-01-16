package com.zeroone.star.project.j3.message;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.MessageDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @description:消息管理Api
 * @author: 坚强少年
 * @date: 2024/1/15 20:36
 **/
public interface MessageApis {
    /**
     * @description:批量删除/撤回接口
     * @author: 坚强少年
     * @date: 2024/1/15 21:51
     * @param: [id]
     * @return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     **/
    JsonVO<Boolean> deleteByIds(Long id);

    /**
     * @description:获取消息详情页。
     * @author: 坚强少年
     * @date: 2024/1/15 21:54
     * @param: [id]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.j3.dto.MessageDTO>
     **/
    JsonVO<PageDTO<MessageDTO>> queryMessageDetail(PageDTO<MessageDTO> detailDTO);
}
