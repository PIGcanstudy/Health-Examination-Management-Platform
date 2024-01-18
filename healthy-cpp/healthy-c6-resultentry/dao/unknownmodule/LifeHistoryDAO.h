#pragma once
#ifndef _GROUP_PERSON_DAO_
#define _GROUP_PERSON_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodule/LifeHistoryDO.h"
#include "../../domain/query/unknownmodule/LifeHistoryQuery.h"

class LifeHistoryDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const LifeHistoryQuery::Wrapper& query);
	// 分页查询数据
	list<LifeHistoryDO> selectWithPage(const LifeHistoryQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
