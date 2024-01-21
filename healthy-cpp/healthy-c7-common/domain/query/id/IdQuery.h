#pragma once
#ifndef _IDQuery_H_
#define _IDQuery_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  ��ѯid����������ɾ�����޸� ʵ��
*/
class IdQuery : public PageQuery {
	DTO_INIT(IdQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("id.field.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IDQUERY_H_