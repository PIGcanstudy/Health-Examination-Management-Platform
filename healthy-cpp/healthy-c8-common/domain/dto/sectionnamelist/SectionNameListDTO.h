#pragma once
#ifndef _SectionNameListDTO_
#define _SectionNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class SectionNameListDTO : public oatpp::DTO
{
	DTO_INIT(SectionNameListDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class SectionNameListPageDTO : public PageDTO<SectionNameListDTO::Wrapper>
{
	DTO_INIT(SectionNameListPageDTO, PageDTO<SectionNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 