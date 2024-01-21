#pragma once
#ifndef _DETAILQUERY_H_
#define _DETAILQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��λ��ҳ��ѯʵ��
 */
class DetailQuery : public PageQuery
{
	DTO_INIT(DetailQuery, PageQuery);
	DTO_FIELD(UInt64, pageSize) = 1;
	// �û�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	// �û�����
	API_DTO_FIELD_DEFAULT(Int32, age, ZH_WORDS_GETTER("unit.field.age"));
	// �û��Ա�
	API_DTO_FIELD_DEFAULT(String, gender, ZH_WORDS_GETTER("unit.field.gender"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETAILQUERY_H_