#include "stdafx.h"
#include "positiveController.h"
#include "../../service/positive/PositiveListService.h"
PositiveListPageJsonVO::Wrapper PositiveConrtoller::execQueryPositive(const PositiveQuery::Wrapper& query)
{	// 定义一个Service
	PositiveListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PositiveListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
