#pragma once
#ifndef _POSITIVEListDTO_H_
#define _POSITIVEListDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ���б������ݶ���ʵ��
 * ���Խ��λ��t_depart_item_result����
 */
class PositiveListDTO : public oatpp::DTO {
	DTO_INIT(PositiveListDTO, DTO);
	// Ψһ��� 
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.filed.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("positive.filed.personname"));
	// ����� t_group_person����
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("positive.filed.test_num"));
	// ������
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("positive.filed.officename"));
	// �����Ŀ
	API_DTO_FIELD_DEFAULT(String, order_group_item_project_name, ZH_WORDS_GETTER("positive.filed.order_group_item_project_name"));
	// ��� �ضȳ̶�
	API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("positive.filed.result"));
	// ��λ
	API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("positive.filed.unit_name"));
	// �ο���Χ
	API_DTO_FIELD_DEFAULT(String, scope, ZH_WORDS_GETTER("positive.filed.scope"));
	// ��ʾ

	// Σ���̶�
	API_DTO_FIELD_DEFAULT(String, crisis_degree, ZH_WORDS_GETTER("positive.filed.crisis_degree"));
	// �������
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("positive.filed.checkdate"));
};

/**
 * ���Խ���б��ҳ����ʵ��
 */
class PositiveListPageDTO : public PageDTO<PositiveListDTO::Wrapper> {
	DTO_INIT(PositiveListPageDTO, PageDTO<PositiveListDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSITIVEListDTO_H_