#pragma once

#ifndef _SELECTBASEPROJECT_SERVICE_
#define _SELECTBASEPROJECT_SERVICE_
#include <list>
#include "domain/vo/baseproject/SelectBaseProjectVO.h"
#include "domain/query/baseproject/SelectBaseProjectQuery.h"
#include "domain/dto/baseproject/SelectBaseProjectDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class SelectBaseProjectService
{
public:
	// ��ҳ��ѯ��������
	SelectBaseProjectPageDTO::Wrapper listAll(const SelectBaseProjectQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const SelectBaseProjectDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const SelectBaseProjectDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SELECTBASEPROJECT_SERVICE_

