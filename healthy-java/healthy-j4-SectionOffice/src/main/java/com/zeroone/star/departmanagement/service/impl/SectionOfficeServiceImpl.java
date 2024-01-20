package com.zeroone.star.departmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.conditions.query.LambdaQueryChainWrapper;
import com.baomidou.mybatisplus.extension.conditions.query.QueryChainWrapper;
import com.baomidou.mybatisplus.extension.conditions.update.LambdaUpdateChainWrapper;
import com.baomidou.mybatisplus.extension.conditions.update.UpdateChainWrapper;
import com.baomidou.mybatisplus.extension.kotlin.KtQueryChainWrapper;
import com.baomidou.mybatisplus.extension.kotlin.KtUpdateChainWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.departmanagement.entity.SectionOffice;
import com.zeroone.star.departmanagement.service.SectionOfficeService;
import org.springframework.stereotype.Service;

import java.io.Serializable;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.function.Function;

/**
 * (SectionOffice)表服务实现类
 *
 * @author makejava
 * @since 2024-01-17 21:52:32
 */
@Service("sectionOfficeService")
public class SectionOfficeServiceImpl  implements SectionOfficeService {
    /**
     * 别管，后面慢慢改
     * @param sectionOffice
     * @return
     */
    @Override
    public Object update(SectionOffice sectionOffice) {
        return null;
    }

    @Override
    public Object deleteById(String id) {
        return null;
    }

    @Override
    public boolean save(SectionOffice entity) {
        return SectionOfficeService.super.save(entity);
    }

    @Override
    public boolean saveBatch(Collection<SectionOffice> entityList) {
        return SectionOfficeService.super.saveBatch(entityList);
    }

    @Override
    public boolean saveBatch(Collection<SectionOffice> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdateBatch(Collection<SectionOffice> entityList) {
        return SectionOfficeService.super.saveOrUpdateBatch(entityList);
    }

    @Override
    public boolean saveOrUpdateBatch(Collection<SectionOffice> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean removeById(Serializable id) {
        return SectionOfficeService.super.removeById(id);
    }

    @Override
    public boolean removeById(SectionOffice entity) {
        return SectionOfficeService.super.removeById(entity);
    }

    @Override
    public boolean removeByMap(Map<String, Object> columnMap) {
        return SectionOfficeService.super.removeByMap(columnMap);
    }

    @Override
    public boolean remove(Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.remove(queryWrapper);
    }

    @Override
    public boolean removeByIds(Collection<? extends Serializable> idList) {
        return SectionOfficeService.super.removeByIds(idList);
    }

    @Override
    public boolean updateById(SectionOffice entity) {
        return SectionOfficeService.super.updateById(entity);
    }

    @Override
    public boolean update(Wrapper<SectionOffice> updateWrapper) {
        return SectionOfficeService.super.update(updateWrapper);
    }

    @Override
    public boolean update(SectionOffice entity, Wrapper<SectionOffice> updateWrapper) {
        return SectionOfficeService.super.update(entity, updateWrapper);
    }

    @Override
    public boolean updateBatchById(Collection<SectionOffice> entityList) {
        return SectionOfficeService.super.updateBatchById(entityList);
    }

    @Override
    public boolean updateBatchById(Collection<SectionOffice> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdate(SectionOffice entity) {
        return false;
    }

    @Override
    public SectionOffice getById(Serializable id) {
        return SectionOfficeService.super.getById(id);
    }

    @Override
    public List<SectionOffice> listByIds(Collection<? extends Serializable> idList) {
        return SectionOfficeService.super.listByIds(idList);
    }

    @Override
    public List<SectionOffice> listByMap(Map<String, Object> columnMap) {
        return SectionOfficeService.super.listByMap(columnMap);
    }

    @Override
    public SectionOffice getOne(Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.getOne(queryWrapper);
    }

    @Override
    public SectionOffice getOne(Wrapper<SectionOffice> queryWrapper, boolean throwEx) {
        return null;
    }

    @Override
    public Map<String, Object> getMap(Wrapper<SectionOffice> queryWrapper) {
        return null;
    }

    @Override
    public <V> V getObj(Wrapper<SectionOffice> queryWrapper, Function<? super Object, V> mapper) {
        return null;
    }

    @Override
    public long count() {
        return SectionOfficeService.super.count();
    }

    @Override
    public long count(Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.count(queryWrapper);
    }

    @Override
    public List<SectionOffice> list(Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.list(queryWrapper);
    }

    @Override
    public List<SectionOffice> list() {
        return SectionOfficeService.super.list();
    }

    @Override
    public <E extends IPage<SectionOffice>> E page(E page, Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.page(page, queryWrapper);
    }

    @Override
    public <E extends IPage<SectionOffice>> E page(E page) {
        return SectionOfficeService.super.page(page);
    }

    @Override
    public List<Map<String, Object>> listMaps(Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.listMaps(queryWrapper);
    }

    @Override
    public List<Map<String, Object>> listMaps() {
        return SectionOfficeService.super.listMaps();
    }

    @Override
    public List<Object> listObjs() {
        return SectionOfficeService.super.listObjs();
    }

    @Override
    public <V> List<V> listObjs(Function<? super Object, V> mapper) {
        return SectionOfficeService.super.listObjs(mapper);
    }

    @Override
    public List<Object> listObjs(Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.listObjs(queryWrapper);
    }

    @Override
    public <V> List<V> listObjs(Wrapper<SectionOffice> queryWrapper, Function<? super Object, V> mapper) {
        return SectionOfficeService.super.listObjs(queryWrapper, mapper);
    }

    @Override
    public <E extends IPage<Map<String, Object>>> E pageMaps(E page, Wrapper<SectionOffice> queryWrapper) {
        return SectionOfficeService.super.pageMaps(page, queryWrapper);
    }

    @Override
    public <E extends IPage<Map<String, Object>>> E pageMaps(E page) {
        return SectionOfficeService.super.pageMaps(page);
    }

    @Override
    public BaseMapper<SectionOffice> getBaseMapper() {
        return null;
    }

    @Override
    public Class<SectionOffice> getEntityClass() {
        return null;
    }

    @Override
    public QueryChainWrapper<SectionOffice> query() {
        return SectionOfficeService.super.query();
    }

    @Override
    public LambdaQueryChainWrapper<SectionOffice> lambdaQuery() {
        return SectionOfficeService.super.lambdaQuery();
    }

    @Override
    public KtQueryChainWrapper<SectionOffice> ktQuery() {
        return SectionOfficeService.super.ktQuery();
    }

    @Override
    public KtUpdateChainWrapper<SectionOffice> ktUpdate() {
        return SectionOfficeService.super.ktUpdate();
    }

    @Override
    public UpdateChainWrapper<SectionOffice> update() {
        return SectionOfficeService.super.update();
    }

    @Override
    public LambdaUpdateChainWrapper<SectionOffice> lambdaUpdate() {
        return SectionOfficeService.super.lambdaUpdate();
    }

    @Override
    public boolean saveOrUpdate(SectionOffice entity, Wrapper<SectionOffice> updateWrapper) {
        return SectionOfficeService.super.saveOrUpdate(entity, updateWrapper);
    }
    /**
     * 模板这样别管
     * @param entity
     * @return
     */

}
