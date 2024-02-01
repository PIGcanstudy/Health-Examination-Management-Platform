package com.zeroone.star.tsectionoffice.mapper;

import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.core.toolkit.Constants;
import com.zeroone.star.tsectionoffice.entity.TSectionOffice;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author AYuan
 * @since 2024-01-16
 */
@Mapper
public interface TSectionOfficeMapper extends BaseMapper<TSectionOffice> {
    /**
     * @Author: ayuan
     * @param: [id]
     * @return: java.lang.String
     * @Description: 根据id查询科室id
     **/
    @Select("SELECT department_id FROM t_user WHERE del_flag = 0 AND id = #{id}")
    String selectByUserId(String id);

}
