#include "stdafx.h"
#include "ReviewController.h"
#include "../../service/review/ReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

ReviewListPageJsonVO::Wrapper ReviewController::execQueryReview(const ReviewQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ReviewService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ReviewListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}