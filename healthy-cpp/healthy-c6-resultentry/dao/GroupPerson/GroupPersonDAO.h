#pragma once

#ifndef _GroupPerson_DAO_
#define _GroupPerson_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GroupPerson/GroupPersonDO.h"
#include "../../domain/query/GroupPerson/GroupPersonQuery.h"

/**
 * 示例表数据库操作实现
 */
class GroupPersonDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GroupPersonQuery::Wrapper& query);
	// 分页查询数据
	list<GroupPersonDO> selectWithPage(const GroupPersonQuery::Wrapper& query);
	// 通过姓名查询数据
	list<GroupPersonDO> selectByName(const string& name);
};
#endif // !_GroupPerson_DAO_
