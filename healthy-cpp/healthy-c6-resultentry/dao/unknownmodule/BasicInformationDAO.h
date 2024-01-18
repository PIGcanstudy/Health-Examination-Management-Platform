#pragma once
#ifndef _GROUP_PERSON_DAO_
#define _GROUP_PERSON_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodule/BasicInformationDO.h"
#include "../../domain/query/unknownmodule/BasicInformationQuery.h"

class BasicInformationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const BasicInformationQuery::Wrapper& query);
	// 分页查询数据
	list<BasicInformationDO> selectWithPage(const BasicInformationQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
