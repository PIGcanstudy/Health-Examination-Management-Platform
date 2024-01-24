package com.zeroone.star.sysmanager.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.sysmanager.entity.TSetting;
import com.zeroone.star.sysmanager.mapper.TSettingMapper;
import com.zeroone.star.sysmanager.service.ITSettingService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 系统配置（系统公告、其他自定义配置） 服务实现类
 * </p>
 *
 * @author car
 * @since 2024-01-24
 */
@Service
public class TSettingServiceImpl extends ServiceImpl<TSettingMapper, TSetting> implements ITSettingService {

}
