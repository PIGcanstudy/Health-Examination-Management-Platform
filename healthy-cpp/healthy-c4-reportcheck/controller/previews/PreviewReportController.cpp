#include "stdafx.h"
#include "PreviewReportController.h"

PreviewReportJsonVO::Wrapper  PreviewReportController::execPreviewReport(const PreviewReportQuery::Wrapper& query) {
	PreviewReportJsonVO::Wrapper vo = PreviewReportJsonVO::Wrapper::createShared();
	auto dto = PreviewReportDTO::createShared();
	vo->fail(dto);
	return vo;
}