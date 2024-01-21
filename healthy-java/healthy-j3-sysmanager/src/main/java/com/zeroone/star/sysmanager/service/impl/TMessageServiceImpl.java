package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import cn.hutool.json.JSONConfig;
import cn.hutool.json.JSONUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.Message;
import com.zeroone.star.sysmanager.entity.MessageSend;
import com.zeroone.star.sysmanager.mapper.MessageMapper;
import com.zeroone.star.sysmanager.mapper.MessageSendMapper;
import com.zeroone.star.sysmanager.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 消息 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TMessageServiceImpl extends ServiceImpl<MessageMapper, Message> implements ITMessageService {

    @Resource
    private MessageSendMapper messageSendMapper;

    @Resource
    private StringRedisTemplate stringRedisTemplate;
    /**
     * @description:从数据库中查询消息详情
     * @author: 坚强少年
     * @date: 2024/1/17 17:05
     * @param: [detailDTO]
     * @return: com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.message.MessageDTO>
     **/
    @Override
    public PageDTO<MessageResponseDTO> selectMessageDetailPage(MessageSendDTO messageSend) {
        //读取数据库获取详情分页信息
        Page page = new Page(messageSend.getPageIndex(),messageSend.getPageSize());
        LambdaQueryWrapper<MessageSend> wrapper = new LambdaQueryWrapper<>();
        if (messageSend.getUserId() != null){
            wrapper.eq(MessageSend::getUserId,messageSend.getUserId());
        }
        page = messageSendMapper.selectPage(page, wrapper);
        PageDTO<MessageResponseDTO> message = PageDTO.create(page);
        return message;
    }
    public JsonVO getJsonVO(MessageSendDTO messageSend) {
        String key = "message:detail:" + messageSend.getMessageId();
        //1.从redis当中查询缓存
        String mesJson = stringRedisTemplate.opsForValue().get(key);
        //2.判断是否命中
        if (StrUtil.isNotBlank(mesJson)) {
            //3.命中直接返回
            PageDTO bean = JSONUtil.toBean(mesJson, PageDTO.class);
            return JsonVO.success(bean);
        }
        //4.不存在从数据库中读取消息详情页，写入redis
        PageDTO<MessageResponseDTO> data = selectMessageDetailPage(messageSend);
        //定义JSONConfig防止日期改为时间戳
        JSONConfig jsonConfig = new JSONConfig();
        jsonConfig.setDateFormat("yyyy-MM-dd");
        stringRedisTemplate.opsForValue().set(key,JSONUtil.toJsonStr(data,jsonConfig), 3, TimeUnit.MINUTES);
        return JsonVO.success(data);
    }
}
