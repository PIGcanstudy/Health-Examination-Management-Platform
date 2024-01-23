#pragma once
#ifndef _GROUP_PERSON_INFO_QUERY_
#define _GROUP_PERSON_INFO_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 人员详情查询实体
 */
class GroupPersonInfoQuery : public oatpp::DTO
{
	DTO_INIT(GroupPersonInfoQuery, DTO);

	// 姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("group_person.field.name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_PERSON_INFO_QUERY_