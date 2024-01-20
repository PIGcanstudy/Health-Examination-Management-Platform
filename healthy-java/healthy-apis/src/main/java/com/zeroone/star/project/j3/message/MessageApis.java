package com.zeroone.star.project.j3.message;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.MsgListQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.ArrayList;

/**
 * @description:消息管理Api
 * @author: 坚强少年
 * @date: 2024/1/15 20:36
 **/
public interface MessageApis {
    /**
     * 消息列表查询接口
     * @param msgListQuery：查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MsgListDTO>> queryMessageList(MsgListQuery msgListQuery);

    /* @description:批量删除/撤回接口
     * @author: 坚强少年
     * @date: 2024/1/15 21:51
     * @param: [id]
     * @return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     **/
    JsonVO<Boolean> deleteByIds(ArrayList<String> ids);

    /**
     * @description:获取消息详情页。
     * @author: 坚强少年
     * @date: 2024/1/15 21:54
     * @param: [id]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.j3.dto.MessageDTO>
     **/
    JsonVO<PageDTO<MessageResponseDTO>> selectMessageDetailPage(MessageSendDTO messageSend);
}
