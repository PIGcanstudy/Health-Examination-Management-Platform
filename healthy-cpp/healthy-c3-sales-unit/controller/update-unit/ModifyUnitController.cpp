#include "stdafx.h"
#include "ModifyUnitController.h"

//修改单位	负责人：kzz
//前端→UnitDetailDTO→后端→Uint64JsonVO(操作成功/失败)→前端
StringJsonVO::Wrapper ModifyUnitController::execModifyUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 参数校验
	// id校验、统一社会信用代码、号码校验
	
	jvo->success(dto->id);

	// 响应结果
	return jvo;
}

