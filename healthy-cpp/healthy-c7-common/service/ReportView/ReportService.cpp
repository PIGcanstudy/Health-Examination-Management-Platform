#include "ReportService.h"
#include "dao/ReportView/ReportDAO.h"
#include "uselib/pdf/InspectPDF.h"
#include "uselib/InspectFastDfs/InspectFastDfs.h"


ReportDTO::Wrapper ReportService::listId(const ReportQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ReportDTO::createShared();
	ReportDAO dao;
	InspectPdf pdf;
	InspectFastDfs FastDfs;
	list<ReportDO> result = dao.selectByName(query->personId);
	// 将DO转换成DTO
	for (ReportDO sub : result)
	{
		auto dto = ReportDTO::createShared();
		pdf.ReportTpl(sub);
		dto->href = FastDfs.InspectDfsWithConf("Report.pdf");
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub);
		pages = dto;
	}
	return pages;
}
