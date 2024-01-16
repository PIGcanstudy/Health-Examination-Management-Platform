#pragma once
#ifndef _CHECKQUERY_H_
#define _CHECKQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
	这是报告审核查询
	负责人 Z
*/
class CheckReportQuery : public PageQuery
{
	DTO_INIT(CheckReportQuery, DTO);
	// 查询类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("Report.field.type"));

	// 姓名
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("Report.field.name"));

	// 订单编号
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("Report.field.orderId"));

	// 体检编号
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("Report.field.testNum"));

	// 单位名称
	API_DTO_FIELD_DEFAULT(String, unit_id, ZH_WORDS_GETTER("Report.field.unitId"));

	// 是否过审
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("Report.field.statu"));

	// 是否复查
	API_DTO_FIELD_DEFAULT(Boolean, is_recheck, ZH_WORDS_GETTER("Report.field.isRecheck"));

	// 体检日期
	API_DTO_FIELD_DEFAULT(String, check_date, ZH_WORDS_GETTER("Report.field.checkDate"));
}; 

#include OATPP_CODEGEN_END(DTO)
#endif //!_CHECKQUERY_H_