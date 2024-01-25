#pragma once
#ifndef _UesrNameListDTO_
#define _UesrNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class UesrNameListDTO : public oatpp::DTO
{
	DTO_INIT(UesrNameListDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class UesrNameListPageDTO : public PageDTO<UesrNameListDTO::Wrapper>
{
	DTO_INIT(UesrNameListPageDTO, PageDTO<UesrNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 