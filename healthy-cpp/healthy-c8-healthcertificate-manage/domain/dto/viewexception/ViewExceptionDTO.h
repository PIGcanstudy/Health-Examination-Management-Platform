#pragma once
#ifndef _ViewExceptionDTO_
#define _ViewExceptionDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class ViewExceptionDTO : public oatpp::DTO
{
	DTO_INIT(ViewExceptionDTO, DTO);
	//TODO : ҳ��Ҫ��ʾ�Ķ���

};

/**
 * ʾ����ҳ�������
 */
class ViewExceptionPageDTO : public PageDTO<ViewExceptionDTO::Wrapper>
{
	DTO_INIT(ViewExceptionPageDTO, PageDTO<ViewExceptionDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_