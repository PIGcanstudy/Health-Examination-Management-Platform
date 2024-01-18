#pragma once
#ifndef _GROUP_PERSON_DAO_
#define _GROUP_PERSON_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodule/ProfessionalHistoryDO.h"
#include "../../domain/query/unknownmodule/ProfessionalHistoryQuery.h"

class ProfessionalHistoryDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ProfessionalHistoryQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ProfessionalHistoryDO> selectWithPage(const ProfessionalHistoryQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
