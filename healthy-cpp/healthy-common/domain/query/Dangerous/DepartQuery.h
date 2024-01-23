#pragma once
#ifdef _DEPARTQUERY_H_
#define _DEPARTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain\query\PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class DepartQuery : public PageQuery {
	DTO_INIT(DepartQuery,DTO);
	//�����ԱID
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("depart.field.officeName"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_

