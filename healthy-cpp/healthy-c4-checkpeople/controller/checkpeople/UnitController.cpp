#include "stdafx.h"
#include "UnitController.h"
#include "../../service/querypeople/QueryPeopleService.h"
#include "../ApiDeclarativeServicesHelper.h"

UnitListPageJsonVO::Wrapper UnitController::execQueryUnit(const UnitQuery::Wrapper& query)
{
	//这儿写默认测试数据，不需要查询数据库

	QueryPeopleService service;
	//查询数据
	auto result = service.listAll(query);
	//响应结果
	auto jvo = UnitListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
