#pragma once

#ifndef _COMMON_DTO_
#define _COMMON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取组合项目列表传输对象
 */
class PackagesListDTO : public oatpp::DTO
{
	DTO_INIT(PackagesListDTO, DTO);
	// 编号
	DTO_FIELD(String, keywords);
	DTO_FIELD_INFO(keywords) {
		info->description = ZH_WORDS_GETTER("common.field.keywords");
	}
};

/**
 * 获取组合项目列表分页传输对象
 */
class PackagesListPageDTO : public PageDTO<PackagesListDTO::Wrapper>
{
	DTO_INIT(PackagesListPageDTO, PageDTO<PackagesListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif