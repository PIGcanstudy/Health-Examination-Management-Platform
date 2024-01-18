#pragma once

#ifndef _GROUP_PERSON_SERVICE_
#define _GROUP_PERSON_SERVICE_
#include <list>
#include "domain/vo/unknownmodule/ProfessionalHistoryVO.h"
#include "domain/query/unknownmodule/ProfessionalHistoryQuery.h"
#include "domain/dto/unknownmodule/ProfessionalHistoryDTO.h"

class ProfessionalHistoryService
{
public:
	// 查询所有数据
	ProfessionalHistoryPageDTO::Wrapper listAll(const ProfessionalHistoryQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

