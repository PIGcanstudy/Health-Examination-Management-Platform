#include "stdafx.h"
#include "PersonController.h"

PersonPageJsonVO::Wrapper PersonController::execQueryByGroupPerson(const PersonQuery::Wrapper& gpq)
{
	// 定义一个Service
	PersonService service;
	// 查询数据
	auto result = service.listAll(gpq);
	// 响应结果
	auto jvo = PersonPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}