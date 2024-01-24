#include "stdafx.h"
#include "criticalModifyController.h"
#include "../../service/critical/CriticalListService.h"
#include "../ApiDeclarativeServicesHelper.h"

CriticalModifyListJsonVO::Wrapper CriticalModifyController::execModifyCritical(const CriticalListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CriticalListService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}
