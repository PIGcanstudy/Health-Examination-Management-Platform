#pragma once

#ifndef _GroupPerson_QUERY_
#define _GroupPerson_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class GroupPersonQuery : public PageQuery
{
	DTO_INIT(GroupPersonQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("group_person.data.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GroupPerson_QUERY_