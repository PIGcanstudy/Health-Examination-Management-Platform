#pragma once
#ifndef _PackageProNameListDTO_
#define _PackageProNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PackageProNameListDTO : public oatpp::DTO
{
	DTO_INIT(PackageProNameListDTO, DTO);
};

/**
 * ʾ����ҳ�������
 */
class PackageProNameListPageDTO : public PageDTO<PackageProNameListDTO::Wrapper>
{
	DTO_INIT(PackageProNameListPageDTO, PageDTO<PackageProNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 