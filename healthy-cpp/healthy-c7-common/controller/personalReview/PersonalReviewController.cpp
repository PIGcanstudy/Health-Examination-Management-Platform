#include "stdafx.h"
#include "PersonalReviewController.h"
#include "../../service/personalReview/PersonalReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

// StringJsonVO
StringJsonVO::Wrapper PersonalReviewController::execUpdatePersonalReview(const PersonalReviewDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	if (dto->personId == "0000")
		jvo->fail("personId 0000 is failtest");
	else
		jvo->success(dto->personId);
	// 响应结果
	return jvo;
}








