#pragma once
#ifndef _DictNameListDTO_
#define _DictNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class DictNameListDTO : public oatpp::DTO
{
	DTO_INIT(DictNameListDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class DictNameListPageDTO : public PageDTO<DictNameListDTO::Wrapper>
{
	DTO_INIT(DictNameListPageDTO, PageDTO<DictNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 