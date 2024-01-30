#include "stdafx.h"
#include "controller/saveRes/saveResController.h"
#include "../../service/saveres/SaveResService.h"


Uint64JsonVO::Wrapper SaveResController::execAddDepartRes(const SaveResDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	string createId = payload.getId();
	
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->personId || !dto->groupItemId || !dto->officeId || !dto->checkDoc || !dto->checkDate)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->personId->empty() || dto->groupItemId->empty() || dto->officeId->empty() || dto->checkDoc->empty() || dto->checkDate->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	SaveResService service;
	
	// 执行数据新增
	uint64_t id = service.saveData(dto, createId);
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
