#pragma once
#ifndef _UesrNameListDTO_
#define _UesrNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class UesrNameListDTO : public oatpp::DTO
{
	DTO_INIT(UesrNameListDTO, DTO);
};

/**
 * ʾ����ҳ�������
 */
class UesrNameListPageDTO : public PageDTO<UesrNameListDTO::Wrapper>
{
	DTO_INIT(UesrNameListPageDTO, PageDTO<UesrNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 