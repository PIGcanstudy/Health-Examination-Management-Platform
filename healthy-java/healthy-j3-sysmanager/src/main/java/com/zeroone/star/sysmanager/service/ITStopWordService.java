package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.sysmanager.entity.StopWord;

/**
 * <p>
 * 禁用词 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITStopWordService extends IService<StopWord> {

    int updateWord(UpdateWordDTO updateWord);
}
