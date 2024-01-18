#pragma once
#ifndef _GROUP_PERSON_DAO_
#define _GROUP_PERSON_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodule/PastMedicalHistoryDO.h"
#include "../../domain/query/unknownmodule/PastMedicalHistoryQuery.h"

class PastMedicalHistoryDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PastMedicalHistoryQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PastMedicalHistoryDO> selectWithPage(const PastMedicalHistoryQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
