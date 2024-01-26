#include "stdafx.h"
#include "ReviewController.h"
#include "../../service/review/ReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

ReviewListPageJsonVO::Wrapper ReviewController::execQueryReview(const ReviewQuery::Wrapper& query)
{
	// ����һ��Service
	ReviewService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ReviewListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//��AddNewItems��ʵ�� ���ӹ��ܣ��˴�Ӧɾ��
//Uint64JsonVO::Wrapper ReviewController::execAddReview(const ReviewListDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->checkProjectId || !dto->checkProjectName || !dto->reviewExplain)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->checkProjectId->empty() || dto->checkProjectName->empty() || dto->reviewExplain->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ����һ��Service
//	ReviewService service;
//	// ִ����������
//	uint64_t id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//��Ӧ���
//	return jvo;
//}
// �޸�����
StringJsonVO::Wrapper ReviewController::execModifyReview(const ReviewListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ReviewService service;
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
// ɾ������
StringJsonVO::Wrapper ReviewController::execRemoveReview(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!id)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ReviewService service;
	// ִ������ɾ��
	if (service.removeData(id.getValue(""))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}