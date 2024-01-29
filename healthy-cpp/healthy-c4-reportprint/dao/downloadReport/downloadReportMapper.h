#pragma once

#ifndef _DOWNLOADREPORT_MAPPER_
#define _DOWNLOADREPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/downloadReportDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class downloadReportMapper : public Mapper<downloadReportDO>
{
public:
	downloadReportDO mapper(ResultSet* resultSet) const override
	{
		downloadReportDO data;

		return data;
	}
};

#endif // !_DOWNLOADREPORT_MAPPER_