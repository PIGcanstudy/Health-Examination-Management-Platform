package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.jwt.JWT;
import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.sysmanager.entity.StopWord;
import com.zeroone.star.sysmanager.mapper.StopWordMapper;
import com.zeroone.star.sysmanager.service.ITStopWordService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

/**
 * <p>
 * 禁用词 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TStopWordServiceImpl extends ServiceImpl<StopWordMapper, StopWord> implements ITStopWordService {
    @Resource
    private StopWordMapper stopWordMapper;

    @Resource
    private StringRedisTemplate stringRedisTemplate;

    @Override
    public StopWordDTO updateWord(UpdateWordDTO updateWord) {
        //数据封装
        StopWord stopWord = new StopWord();
        stopWord.setId(updateWord.getId());
        stopWord.setTitle(updateWord.getTitle());
        stopWord.setUpdateBy();
        stopWordMapper.updateById()
        return null;
    }
}
