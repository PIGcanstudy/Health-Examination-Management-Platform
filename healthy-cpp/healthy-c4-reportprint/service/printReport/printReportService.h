#pragma once
 
#ifndef _PRINTREPORT_SERVICE_
#define _PRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/printReportVO.h"
#include "domain/query/printReportQuery.h"
#include "domain/dto/printReportDTO.h"

class printReportService
{
public:
	bool updateData(const printReportDTO::Wrapper& dto);
};

#endif // !_PRINTREPORT_SERVICE_

