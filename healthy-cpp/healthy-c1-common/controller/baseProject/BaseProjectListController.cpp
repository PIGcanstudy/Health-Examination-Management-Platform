#include "stdafx.h"
#include "BaseProjectController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/baseproject/SelectBaseProject/SelectBaseProjectService.h"

Uint64JsonVO::Wrapper BaseProjectController::execAddBaseProject(const AddBaseProjectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	// ִ����������

	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper BaseProjectController::execSelectBaseProject(const SelectBaseProjectQuery::Wrapper& query)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

Uint64JsonVO::Wrapper BaseProjectController::execSelectBaseProjectList(const SelectBaseProjectListQuery::Wrapper& query)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	// ִ����������

	//��Ӧ���
	return jvo;
}