#pragma once

#ifndef _GROUP_PERSON_SERVICE_
#define _GROUP_PERSON_SERVICE_
#include <list>
#include "domain/vo/unknownmodule/LifeHistoryVO.h"
#include "domain/query/unknownmodule/LifeHistoryQuery.h"
#include "domain/dto/unknownmodule/LifeHistoryDTO.h"

class LifeHistoryService
{
public:
	// 查询所有数据
	LifeHistoryPageDTO::Wrapper listAll(const LifeHistoryQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

