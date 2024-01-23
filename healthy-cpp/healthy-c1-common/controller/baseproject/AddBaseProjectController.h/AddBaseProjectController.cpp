#include "AddBaseProjectController.h"
#include "../../../service/baseproject/AddBaseProject/AddBaseProjectService.h"

Uint64JsonVO::Wrapper AddBaseProjectController::execAddBaseProject(const AddBaseProjectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ����һ��Service
	AddBaseProjectService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	std::cout << id << std::endl;
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}
