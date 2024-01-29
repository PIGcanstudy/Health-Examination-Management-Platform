 
#include "stdafx.h"
#include "printReportService.h"
#include "../../dao/printReport/printReportDAO.h"

bool printReportService::updateData(const printReportDTO::Wrapper& dto)
{
	// ��װDO����
	printReportDO data;
	data.setId(dto->id.getValue(""));
	data.setReportPrintingNum(dto->report_printing_num.getValue(1));
	data.setPrintState(dto->print_state.getValue(1));

	// ִ�������޸�
	printReportDAO dao;
	return dao.update(data) == 1;
}


