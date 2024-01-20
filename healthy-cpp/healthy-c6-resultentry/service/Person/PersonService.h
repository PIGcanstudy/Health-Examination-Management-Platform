#pragma once

#ifndef _PERSON_SERVICE_
#define _PERSON_SERVICE_
#include <list>
#include "domain/vo/Person/PersonVO.h"
#include "domain/query/Person/PersonQuery.h"
#include "domain/dto/Person/PersonDTO.h"

class PersonService
{
public:
	// ��ҳ��ѯ��������
	PersonPageDTO::Wrapper listAll(const PersonQuery::Wrapper& query);
};

#endif // !_PERSON_SERVICE_

