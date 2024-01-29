#pragma once

#ifndef _printReport_DAO_
#define _printReport_DAO_
#include "BaseDAO.h"
#include "../../domain/do/printReportDO.h"
#include "../../domain/query/printReportQuery.h"

/**
 * 示例表数据库操作实现
 */
class printReportDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const printReportDO& uObj);
};


#endif // !_printReport_DAO_
