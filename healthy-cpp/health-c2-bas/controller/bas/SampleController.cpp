#include "SampleController.h"
#include "stdafx.h"
#include "../../domain/dto/bas/SampleDTO.h"
#include "../../service/bas/SampleService.h"

StringJsonVO::Wrapper SampleController::execModifySample(const SampleDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (dto->id == "")
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SampleService service;
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