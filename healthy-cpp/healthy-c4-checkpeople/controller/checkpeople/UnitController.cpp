#include "stdafx.h"
#include "UnitController.h"
#include "../../service/querypeople/QueryPeopleService.h"
#include "../ApiDeclarativeServicesHelper.h"

UnitListPageJsonVO::Wrapper UnitController::execQueryUnit(const UnitQuery::Wrapper& query)
{
	//���дĬ�ϲ������ݣ�����Ҫ��ѯ���ݿ�

	QueryPeopleService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = UnitListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
