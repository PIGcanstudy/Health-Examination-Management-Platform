#include "stdafx.h"
#include "PersonalReviewController.h"
#include "../../service/personalReview/PersonalReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

// StringJsonVO
StringJsonVO::Wrapper PersonalReviewController::execUpdatePersonalReview(const PersonalReviewDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	if (dto->personId == "0000")
		jvo->fail("personId 0000 is failtest");
	else
		jvo->success(dto->personId);
	// ��Ӧ���
	return jvo;
}








