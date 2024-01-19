package com.zeroone.star.project.j3.message;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.MsgListQuery;
import com.zeroone.star.project.vo.JsonVO;

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
}
