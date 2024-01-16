#pragma once
#ifndef _CHECKQUERY_H_
#define _CHECKQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
	���Ǳ�����˲�ѯ
	������ Z
*/
class CheckReportQuery : public PageQuery
{
	DTO_INIT(CheckReportQuery, DTO);
	// ��ѯ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("Report.field.type"));

	// ����
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("Report.field.name"));

	// �������
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("Report.field.orderId"));

	// �����
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("Report.field.testNum"));

	// ��λ����
	API_DTO_FIELD_DEFAULT(String, unit_id, ZH_WORDS_GETTER("Report.field.unitId"));

	// �Ƿ����
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("Report.field.statu"));

	// �Ƿ񸴲�
	API_DTO_FIELD_DEFAULT(Boolean, is_recheck, ZH_WORDS_GETTER("Report.field.isRecheck"));

	// �������
	API_DTO_FIELD_DEFAULT(String, check_date, ZH_WORDS_GETTER("Report.field.checkDate"));
}; 

#include OATPP_CODEGEN_END(DTO)
#endif //!_CHECKQUERY_H_