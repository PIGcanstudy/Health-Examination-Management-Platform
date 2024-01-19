#pragma once
#ifndef _UNITQUERY_H_
#define _UNITQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

//��λ��ҳ��ѯʵ��
class UnitQuery : public PageQuery
{
public:
	DTO_INIT(UnitQuery, PageQuery);
	//��ѯ����
	API_DTO_FIELD_DEFAULT(UInt32, mytype, ZH_WORDS_GETTER("unit.field.type"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//���ô���
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.name"));
	//��ϵ��
	API_DTO_FIELD_DEFAULT(String, linkMan, ZH_WORDS_GETTER("unit.field.linkMan"));
	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, linkPhone, ZH_WORDS_GETTER("unit.field.linkPhone"));
};


#include OATPP_CODEGEN_END(DTO)

#endif