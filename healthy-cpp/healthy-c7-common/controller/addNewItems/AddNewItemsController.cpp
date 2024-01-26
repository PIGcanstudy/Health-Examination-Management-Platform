#include "stdafx.h"
#include "AddNewItemsController.h"
#include "../../service/addNewItems/AddNewItemsService.h"
#include "../ApiDeclarativeServicesHelper.h"
//查询在Review中进行，此处应删除
//AddNewItemsPageJsonVO::Wrapper AddNewItemsController::execQueryAddNewItems(const AddNewItemsQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// 定义一个Service
//	AddNewItemsService service;
//	// 查询数据
//	auto result = service.listAll(query);
//	// 响应结果
//	auto jvo = AddNewItemsPageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}

Uint64JsonVO::Wrapper AddNewItemsController::execAddAddNewItems(const AddNewItemsDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->checkProjectId || !dto->checkProjectName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->checkProjectId->empty() || dto->checkProjectName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AddNewItemsService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}