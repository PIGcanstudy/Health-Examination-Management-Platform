#include "stdafx.h"
#include "CheckReportController.h"

CheckReportListPageJsonVO::Wrapper CheckReportController::execCheckReport(const CheckReportQuery::Wrapper& query) {
	CheckReportListPageJsonVO::Wrapper vo = CheckReportListPageJsonVO::createShared();
	auto dto = CheckReportListPageDTO::createShared();
	if (query->pageIndex == 1) {
		vo->success(dto);
	}
	else {
		vo->fail(dto);
	}
	return vo;
}