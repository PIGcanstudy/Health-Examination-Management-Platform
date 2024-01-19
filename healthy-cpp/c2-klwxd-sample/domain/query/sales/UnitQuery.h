#pragma once
#ifndef _UNITQUERY_H_
#define _UNITQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

//单位分页查询实体
class UnitQuery : public PageQuery
{
public:
	DTO_INIT(UnitQuery, PageQuery);
	//查询类型
	API_DTO_FIELD_DEFAULT(UInt32, mytype, ZH_WORDS_GETTER("unit.field.type"));
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//信用代码
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.name"));
	//联系人
	API_DTO_FIELD_DEFAULT(String, linkMan, ZH_WORDS_GETTER("unit.field.linkMan"));
	//联系电话
	API_DTO_FIELD_DEFAULT(String, linkPhone, ZH_WORDS_GETTER("unit.field.linkPhone"));
};


#include OATPP_CODEGEN_END(DTO)

#endif