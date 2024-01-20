#include "stdafx.h"
#include "PersonController.h"

PersonPageJsonVO::Wrapper PersonController::execQueryByGroupPerson(const PersonQuery::Wrapper& gpq)
{
	// ����һ��Service
	PersonService service;
	// ��ѯ����
	auto result = service.listAll(gpq);
	// ��Ӧ���
	auto jvo = PersonPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}