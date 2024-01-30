#pragma once
 
#ifndef _PRINTREPORT_SERVICE_
#define _PRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/PrintReportVO.h"
#include "domain/query/PrintReportQuery.h"
#include "domain/dto/PrintReportDTO.h"

class PrintReportService
{
public:
	bool updateData(const PrintReportDTO::Wrapper& dto);
};

#endif // !_PRINTREPORT_SERVICE_

