#pragma once

#ifndef _SELECTBASEPROJECTDAO_H_
#define _SELECTBASEPROJECTDAO_H_
#include "BaseDAO.h"
#include "../../../domain/do/baseproject/SelectBaseProjectDO.h"
#include "../../../domain/query/baseproject/SelectBaseProjectQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SelectBaseProjectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const SelectBaseProjectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<SelectBaseProjectDO> selectWithPage(const SelectBaseProjectQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<SelectBaseProjectDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const SelectBaseProjectDO& iObj);
	// �޸�����
	int update(const SelectBaseProjectDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_SELECTBASEPROJECTDAO_H_
