#ifndef _REPORTQUERY_H_
#define _REPORTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ReportQuery : public PageQuery
{
	DTO_INIT(ReportQuery, PageQuery);
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, begDate, ZH_WORDS_GETTER("unit.begDate"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("unit.endDate"));
	//��쵥λ
	API_DTO_FIELD_DEFAULT(String, phyUnit, ZH_WORDS_GETTER("unit.phyUnit"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_#pragma once
