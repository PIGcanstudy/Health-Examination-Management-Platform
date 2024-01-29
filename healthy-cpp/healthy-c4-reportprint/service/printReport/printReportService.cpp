 
#include "stdafx.h"
#include "printReportService.h"
#include "../../dao/printReport/printReportDAO.h"

bool printReportService::updateData(const printReportDTO::Wrapper& dto)
{
	// 组装DO数据
	printReportDO data;
	data.setId(dto->id.getValue(""));
	data.setReportPrintingNum(dto->report_printing_num.getValue(1));
	data.setPrintState(dto->print_state.getValue(1));

	// 执行数据修改
	printReportDAO dao;
	return dao.update(data) == 1;
}


