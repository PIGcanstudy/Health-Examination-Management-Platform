#include "PlanNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"

PlanNameListPageJsonVO::Wrapper PlanNameListController::execQueryPlanNameList(const String& keyword, const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, PlanNameListApiClient, "query-plannamelist-api");
	// ���ؽ��
	return ac->queryPlanNameList(token,keyword)->readBodyToDto<PlanNameListPageJsonVO::Wrapper>(om);
}
