#ifndef _UNITQUERY_
#define _UNITQUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class UnitQuery : public PageQuery
{
	DTO_INIT(UnitQuery, DTO);
	//��ѯ����
	API_DTO_FIELD(UInt32, type, ZH_WORDS_GETTER(uint.field.type));
	//��λ����
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER(uint.field.name));
	//���ô���
	API_DTO_FIELD(String, uscc, ZH_WORDS_GETTER(uint.field.uscc));
	//��ϵ��
	API_DTO_FIELD(String, linkMan, ZH_WORDS_GETTER(uint.field.linkMan));
	//��ϵ�绰
	API_DTO_FIELD(String, linkPhone, ZH_WORDS_GETTER(uint.field.linkPhone));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
