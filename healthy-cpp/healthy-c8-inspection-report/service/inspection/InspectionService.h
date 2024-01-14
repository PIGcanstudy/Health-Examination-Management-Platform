#pragma once

#ifndef _INSPECTION_SERVICE_
#define _INSPECTION_SERVICE_

#include <list>
#include "domain/vo/inspection/InspectionVO.h"
#include "domain/query/inspection/InspectionQuery.h"
#include "domain/dto/inspection/InspectionDTO.h"


/**
 * �Ӽ챨���б����ʵ��
 */
class ReportListService
{
public:
	// ��ҳ��ѯ��������
	ReportListPageDTO::Wrapper listAll(const ReportListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ReportListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ReportListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};


#endif

