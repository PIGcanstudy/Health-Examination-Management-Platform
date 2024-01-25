#pragma once
#ifndef _TypeTreeDTO_
#define _TypeTreeDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class TypeTreeDTO : public oatpp::DTO
{
	DTO_INIT(TypeTreeDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class TypeTreePageDTO : public PageDTO<TypeTreeDTO::Wrapper>
{
	DTO_INIT(TypeTreePageDTO, PageDTO<TypeTreeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 