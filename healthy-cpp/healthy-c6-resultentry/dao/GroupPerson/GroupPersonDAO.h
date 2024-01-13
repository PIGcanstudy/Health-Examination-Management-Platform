#pragma once

#ifndef _GroupPerson_DAO_
#define _GroupPerson_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GroupPerson/GroupPersonDO.h"
#include "../../domain/query/GroupPerson/GroupPersonQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class GroupPersonDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GroupPersonQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GroupPersonDO> selectWithPage(const GroupPersonQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<GroupPersonDO> selectByName(const string& name);
};
#endif // !_GroupPerson_DAO_
