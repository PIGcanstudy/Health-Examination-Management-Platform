#include "stdafx.h"
#include "positiveController.h"
#include "../../service/positive/PositiveListService.h"
PositiveListPageJsonVO::Wrapper PositiveConrtoller::execQueryPositive(const PositiveQuery::Wrapper& query)
{	// ����һ��Service
	PositiveListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = PositiveListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
