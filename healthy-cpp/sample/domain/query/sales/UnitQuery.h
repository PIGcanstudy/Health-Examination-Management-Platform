#ifndef _UNITQUERY_
#define _UNITQUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class UnitQuery : public PageQuery
{
	DTO_INIT(UnitQuery, DTO);
	//查询类型
	API_DTO_FIELD(UInt32, type, ZH_WORDS_GETTER(uint.field.type));
	//单位名称
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER(uint.field.name));
	//信用代码
	API_DTO_FIELD(String, uscc, ZH_WORDS_GETTER(uint.field.uscc));
	//联系人
	API_DTO_FIELD(String, linkMan, ZH_WORDS_GETTER(uint.field.linkMan));
	//联系电话
	API_DTO_FIELD(String, linkPhone, ZH_WORDS_GETTER(uint.field.linkPhone));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
