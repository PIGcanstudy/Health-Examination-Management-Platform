#pragma once
#ifndef _INTERRO_DTO_
#define _INTERRO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 症状询问传输对象
 */
class InterroDTO : public oatpp::DTO
{
	DTO_INIT(InterroDTO, DTO);
	// 体检人编号
	DTO_FIELD(Int32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("interro.field.id");
	}
	// 体检项目
	DTO_FIELD(String, project);
	DTO_FIELD_INFO(project) {
		info->description = ZH_WORDS_GETTER("interro.field.project");
	}
	// 危急程度
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("interro.field.degree");
	}
	// 病程时间
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("interro.field.time");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_INTERRO_DTO_