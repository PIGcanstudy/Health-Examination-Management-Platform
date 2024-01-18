#pragma once

#ifndef _GROUP_PERSON_SERVICE_
#define _GROUP_PERSON_SERVICE_
#include <list>
#include "domain/vo/unknownmodule/PastMedicalHistoryVO.h"
#include "domain/query/unknownmodule/PastMedicalHistoryQuery.h"
#include "domain/dto/unknownmodule/PastMedicalHistoryDTO.h"

class PastMedicalHistoryService
{
public:
	// 查询所有数据
	PastMedicalHistoryPageDTO::Wrapper listAll(const PastMedicalHistoryQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

