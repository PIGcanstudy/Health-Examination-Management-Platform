#pragma once
#ifndef _INTERRO_DAO_
#define _INTERRO_DAO_
#include "BaseDAO.h"
#include"../../domain/do/interro/InterroDO.h"
#include"../../domain/query/interro/InterroQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class InterroDAO : public BaseDAO
{
public:
	// ��ѯ����
	list<InterroDO> selectWith(const InterroQuery::Wrapper& query);
};
#endif // !_INTERRO_DAO_
