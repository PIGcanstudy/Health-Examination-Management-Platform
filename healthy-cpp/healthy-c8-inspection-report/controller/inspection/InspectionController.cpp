#include "stdafx.h"
#include "InspectionController.h"
#include "../../service/inspection/InspectionService.h"
#include "../ApiDeclarativeServicesHelper.h"

ReportListPageJsonVO::Wrapper InspectionController::execQueryReportList(const ReportListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ReportListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ReportListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
