#pragma once
#ifndef _JobNameListDTO_
#define _JobNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class JobNameListDTO : public oatpp::DTO
{
	DTO_INIT(JobNameListDTO, DTO);
};

/**
 * ʾ����ҳ�������
 */
class JobNameListPageDTO : public PageDTO<JobNameListDTO::Wrapper>
{
	DTO_INIT(JobNameListPageDTO, PageDTO<JobNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 