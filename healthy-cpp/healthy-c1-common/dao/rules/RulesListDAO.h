#pragma once
#ifndef _RULESLIST_DAO_
#define _RULESLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/rules/RulesListDO.h"
#include "../../domain/query/rules/RulesListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RulesListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const RulesListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<RulesListDO> selectWithPage(const RulesListQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<RulesListDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const RulesListDO& iObj);
	// �޸�����
	int update(const RulesListDO& uObj);
	// ͨ��IDɾ������
	int deleteById(const string id);
};
#endif // !_RULESLIST_DAO_
