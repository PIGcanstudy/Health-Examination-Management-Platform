#include "stdafx.h"
#include "InspectionController.h"
#include "../../service/inspection/InspectionService.h"
#include "../ApiDeclarativeServicesHelper.h"

ReportListPageJsonVO::Wrapper InspectionController::execQueryReportList(const ReportListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ReportListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ReportListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
