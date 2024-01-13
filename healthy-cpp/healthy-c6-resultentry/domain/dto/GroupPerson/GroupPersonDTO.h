#pragma once

#ifndef _GroupPerson_DTO_
#define _GroupPerson_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class GroupPersonDTO : public oatpp::DTO
{
	DTO_INIT(GroupPersonDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("group_person.data.name");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("group_person.data.name");
	}
};

/**
 * 示例分页传输对象
 */
class GroupPersonPageDTO : public PageDTO<GroupPersonDTO::Wrapper>
{
	DTO_INIT(GroupPersonPageDTO, PageDTO<GroupPersonDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GroupPerson_DTO_