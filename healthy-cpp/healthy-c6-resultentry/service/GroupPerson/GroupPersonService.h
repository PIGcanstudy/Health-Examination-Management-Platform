#pragma once

#ifndef _GroupPerson_SERVICE_
#define _GroupPerson_SERVICE_
#include <list>
#include "domain/vo/GroupPerson/GroupPersonVO.h"
#include "domain/query/GroupPerson/GroupPersonQuery.h"
#include "domain/dto/GroupPerson/GroupPersonDTO.h"

class GroupPersonService
{
public:
	// 分页查询所有数据
	GroupPersonPageDTO::Wrapper listAll(const GroupPersonQuery::Wrapper& query);
};

#endif // !_GroupPerson_SERVICE_

