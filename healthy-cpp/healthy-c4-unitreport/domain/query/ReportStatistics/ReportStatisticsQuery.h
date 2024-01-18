#pragma once

#ifndef _REPORTSTATISTICSQUERY_
#define _REPORTSTATISTICSQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ReportStatisticsQuery : public PageQuery
{
	//�����ʼ��
	DTO_INIT(ReportStatisticsQuery, PageQuery);
	//�������
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("unitreport.order.code"));
	//ͳ�Ʊ���������������ʾ1��"�����Ա���ܱ�" 2��"������Ա���ܱ�" 3��"���������ܱ�"
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("unitreport.summaryTable.type"));
};

#include OATPP_CODEGEN_END(DTO)

#endif


