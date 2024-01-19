package com.zeroone.star.sysmanager.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageDetailDTO;
import com.zeroone.star.sysmanager.entity.Message;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 消息 Mapper 接口
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Mapper
public interface MessageMapper extends BaseMapper<Message> {

    List<MessageDetailDTO> queryMessageDetail(MessageDetailDTO detailDTO);
}
