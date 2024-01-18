package com.zeroone.star.department.service;

import com.zeroone.star.department.entity.TDepartment;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 部门 服务类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
public interface ITDepartmentService extends IService<TDepartment> {

    void updateUpdateBy(String[] ids, String username);
}
