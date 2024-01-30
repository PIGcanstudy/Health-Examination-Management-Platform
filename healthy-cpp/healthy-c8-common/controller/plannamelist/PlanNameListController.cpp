#include "PlanNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"

PlanNameListPageJsonVO::Wrapper PlanNameListController::execQueryPlanNameList(const String& keyword, const PayloadDTO& payload)
{
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, PlanNameListApiClient, "query-plannamelist-api");
	// 返回结果
	return ac->queryPlanNameList(token,keyword)->readBodyToDto<PlanNameListPageJsonVO::Wrapper>(om);
}
