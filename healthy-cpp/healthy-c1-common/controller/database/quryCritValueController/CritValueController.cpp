#include "CritValueController.h"
#include "../../../domain/vo/database/CritValueVO.h"
#include "../../../domain/query/database/CritValuePageQuery.h"
#include "../../../service/database/CritValueService.h"


CritValuePageJsonVO::Wrapper CritValueController::execQueryPageCritValue(const CritValuePageQuery::Wrapper& query)
{
	//// ����һ��Service
	//CriValueService service;
	//// ��ѯ����
	//auto result = service.listAll(query);
	//// ��Ӧ���
	//auto jvo = CritValuePageJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
	return {};
}
