#pragma once
#ifndef _TypeTreeDTO_
#define _TypeTreeDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class TypeTreeDTO : public oatpp::DTO
{
	DTO_INIT(TypeTreeDTO, DTO);
};

/**
 * ʾ����ҳ�������
 */
class TypeTreePageDTO : public PageDTO<TypeTreeDTO::Wrapper>
{
	DTO_INIT(TypeTreePageDTO, PageDTO<TypeTreeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 