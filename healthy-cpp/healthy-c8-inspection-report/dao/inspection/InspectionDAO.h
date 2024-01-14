#pragma once

#ifndef _INSPECTION_DAO_
#define _INSPECTION_DAO_

#include "BaseDAO.h"
#include "../../domain/do/inspection/InspectionDO.h"
#include "../../domain/query/inspection/InspectionQuery.h"

/**
 * 报告列表数据库操作实现
 */
class ReportListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ReportListQuery::Wrapper& query);
	// 分页查询数据
	list<ReportListDO> selectWithPage(const ReportListQuery::Wrapper& query);

	// 通过体检编号查询数据
	list<ReportListDO> selectByTest_num(const string& test_num);
	// 通过体检单位查询数据
	list<ReportListDO> selectByPhysical_unit(const string& physical_unit);
	// 通过身份证号查询数据
	list<ReportListDO> selectById_card(const string& id_card);
	// 通过体检日期查询数据
	list<ReportListDO> selectByCheck_date(const string& check_date);
	// 通过审核状态查询数据
	list<ReportListDO> selectByStatu(const int& statu);
	// 通过姓名查询数据
	list<ReportListDO> selectByName(const string& name);
	// 通过性别查询数据
	list<ReportListDO> selectBySex(const string& sex);
	// 通过年龄查询数据
	list<ReportListDO> selectByAge(const int& age);
};


#endif

