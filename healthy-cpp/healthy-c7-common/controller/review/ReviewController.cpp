#include "stdafx.h"
#include "ReviewController.h"
#include "../../service/review/ReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

ReviewListPageJsonVO::Wrapper ReviewController::execQueryReview(const ReviewQuery::Wrapper& query, const PayloadDTO& payload)
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