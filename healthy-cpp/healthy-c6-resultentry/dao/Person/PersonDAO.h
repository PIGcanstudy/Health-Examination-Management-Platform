#pragma once
#ifndef _PERSON_DAO_
#define _PERSON_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Person/PersonDO.h"
#include "../../domain/query/Person/PersonQuery.h"

class PersonDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PersonQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PersonDO> selectWithPage(const PersonQuery::Wrapper& query);
};
#endif // !_PERSON_DAO_
