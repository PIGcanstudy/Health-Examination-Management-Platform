#pragma once

#ifndef _REPORTSTATISTICSQUERY_
#define _REPORTSTATISTICSQUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnitPhysicalExaminationOrdersQuery : public Query
{
	//定义初始化
	DTO_INIT(UnitPhysicalExaminationOrdersQuery, Query);
	//订单编号
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("unitreport.order.code"));
	//统计表类型
	API_DTO_FIELD_DEFAULT(String, type);

};

#include OATPP_CODEGEN_END(DTO)

#endif


