#pragma once

#ifndef _GROUP_PERSON_SERVICE_
#define _GROUP_PERSON_SERVICE_
#include <list>
#include "domain/vo/unknownmodule/BasicInformationVO.h"
#include "domain/query/unknownmodule/BasicInformationQuery.h"
#include "domain/dto/unknownmodule/BasicInformationDTO.h"

class BasicInformationService
{
public:
	// 查询所有数据
	BasicInformationPageDTO::Wrapper listAll(const BasicInformationQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

