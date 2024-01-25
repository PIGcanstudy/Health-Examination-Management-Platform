#pragma once
#ifndef _DictNameListDTO_
#define _DictNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class DictNameListDTO : public oatpp::DTO
{
	DTO_INIT(DictNameListDTO, DTO);
};

/**
 * ʾ����ҳ�������
 */
class DictNameListPageDTO : public PageDTO<DictNameListDTO::Wrapper>
{
	DTO_INIT(DictNameListPageDTO, PageDTO<DictNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 