#pragma once

#ifndef _SELECTBASEPROJECTLIST_SERVICE_H_
#define _SELECTBASEPROJECTLIST_SERVICE_H_
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
};

#endif // !_SELECTBASEPROJECTLIST_SERVICE_H_

