#pragma once

#ifndef _REPORTSTATISTICSQUERY_
#define _REPORTSTATISTICSQUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnitPhysicalExaminationOrdersQuery : public Query
{
	//�����ʼ��
	DTO_INIT(UnitPhysicalExaminationOrdersQuery, Query);
	//�������
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("unitreport.order.code"));
	//ͳ�Ʊ�����
	API_DTO_FIELD_DEFAULT(String, type);

};

#include OATPP_CODEGEN_END(DTO)

#endif


