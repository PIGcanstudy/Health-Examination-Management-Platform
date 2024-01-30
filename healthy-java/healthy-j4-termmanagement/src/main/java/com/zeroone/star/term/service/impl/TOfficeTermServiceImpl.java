package com.zeroone.star.term.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.entity.TOfficeTerm;
import com.zeroone.star.term.mapper.TOfficeTermMapper;
import com.zeroone.star.term.service.ITOfficeTermService;
import lombok.val;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.time.LocalDateTime;


@Service
public class TOfficeTermServiceImpl extends ServiceImpl<TOfficeTermMapper, TOfficeTerm> implements ITOfficeTermService {

    @Resource
    private TOfficeTermMapper tOfficeTermMapper;
    @Resource
    private UserHolder userHolder;

    /**
     * @Author: ayuan
     * @param: [termDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 更新术语
     **/
    @Override
    public JsonVO<ResultStatus> updateOfficeTerm(TermDTO termDTO) {
        // 判断数据是否已经被删除
        TOfficeTerm tOfficeTerm1 = getOfficeTerm(termDTO.getId());
        if (tOfficeTerm1.getDelFlag() == 1) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "数据已经被删除");

        // 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取当前用户失败");
        }
        if (currentUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前用户不存在");

        // 封装数据
        val tOfficeTerm = new TOfficeTerm();
        // 拷贝数据
        BeanUtils.copyProperties(termDTO, tOfficeTerm);
        // 设定修改人
        tOfficeTerm.setUpdateId(String.valueOf(currentUser.getId()));
        // 设定修改时间
        tOfficeTerm.setUpdateTime(LocalDateTime.now());
        // 执行修改
        int result = tOfficeTermMapper.updateById(tOfficeTerm);
        // 更新失败
        if (result <= 0) return JsonVO.fail(ResultStatus.FAIL);

        return JsonVO.success(ResultStatus.SUCCESS);
    }

    /**
     * @Author: ayuan
     * @param: [id]
     * @return: com.zeroone.star.term.entity.TOfficeTerm
     * @Description: 根据id获取术语
     **/
    public TOfficeTerm getOfficeTerm(String id) {
        return tOfficeTermMapper.selectById(id);
    }
}
