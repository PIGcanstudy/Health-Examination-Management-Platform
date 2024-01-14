#pragma once

#ifndef _INSPECTION_SERVICE_
#define _INSPECTION_SERVICE_

#include <list>
#include "domain/vo/inspection/InspectionVO.h"
#include "domain/query/inspection/InspectionQuery.h"
#include "domain/dto/inspection/InspectionDTO.h"


/**
 * 从检报告列表服务实现
 */
class ReportListService
{
public:
	// 分页查询所有数据
	ReportListPageDTO::Wrapper listAll(const ReportListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ReportListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ReportListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};


#endif

