#pragma once
#ifndef _PackageProNameListDTO_
#define _PackageProNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PackageProNameListDTO : public oatpp::DTO
{
	DTO_INIT(PackageProNameListDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class PackageProNameListPageDTO : public PageDTO<PackageProNameListDTO::Wrapper>
{
	DTO_INIT(PackageProNameListPageDTO, PageDTO<PackageProNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 