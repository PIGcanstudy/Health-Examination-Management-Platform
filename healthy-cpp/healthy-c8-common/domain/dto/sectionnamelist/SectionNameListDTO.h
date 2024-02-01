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

#include OATPP_CODEGEN_END(DTO)
#endif 