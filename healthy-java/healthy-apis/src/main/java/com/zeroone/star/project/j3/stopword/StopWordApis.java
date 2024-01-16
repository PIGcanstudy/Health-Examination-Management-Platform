package com.zeroone.star.project.j3.stopword;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 *
 * @Author Qi
 * @Date 2024/1/16
 */
public interface StopWordApis {
    /**
     * 查询禁用词
     *
     * @param  query 查询条件
     * @return 包含禁用词详情的分页结果
     */
    JsonVO<PageDTO<StopWordDTO>> queryStopWord(PageDTO<StopWordDTO> query);
    /**
     * 增加禁用词
     *
     * @param title 要添加的禁用词
     * @return 添加禁用词的结果
     */
    JsonVO<String> addStopWord(String title);

}
