#pragma once
#ifndef _RULESLIST_DAO_
#define _RULESLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/rules/RulesListDO.h"
#include "../../domain/query/rules/RulesListQuery.h"

/**
 * 示例表数据库操作实现
 */
class RulesListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const RulesListQuery::Wrapper& query);
	// 分页查询数据
	list<RulesListDO> selectWithPage(const RulesListQuery::Wrapper& query);
	// 通过姓名查询数据
	list<RulesListDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const RulesListDO& iObj);
	// 修改数据
	int update(const RulesListDO& uObj);
	// 通过ID删除数据
	int deleteById(const string id);
};
#endif // !_RULESLIST_DAO_
