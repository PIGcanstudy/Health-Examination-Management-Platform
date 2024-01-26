#pragma once
#ifndef _UNIT_PEOPLE_QUERY_
#define _UNIT_PEOPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ա������ϸ��Ϣ��ѯ����
 */
class UnitPeopleQuery : public PageQuery
{
	DTO_INIT(UnitPeopleQuery, PageQuery);
	// ������
	DTO_FIELD(String, orderId);
	DTO_FIELD_INFO(orderId) {
		info->description = ZH_WORDS_GETTER("unit.field.orderId");
	}
	// ��ѯ��Ա֤����
	DTO_FIELD(String, idCard);
	DTO_FIELD_INFO(idCard) {
		info->description = ZH_WORDS_GETTER("unit.field.idCard");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNIT_PEOPLE_QUERY_