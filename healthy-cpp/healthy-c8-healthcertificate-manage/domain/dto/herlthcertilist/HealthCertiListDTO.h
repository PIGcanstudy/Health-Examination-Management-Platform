#pragma once
#ifndef _HealthCertiListDTO_
#define _HealthCertiListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class HealthCertiListDTO : public oatpp::DTO
{
	DTO_INIT(HealthCertiListDTO, DTO);
	//TODO : ҳ��Ҫ��ʾ�Ķ���

};

/**
 * ʾ����ҳ�������
 */
class HealthCertiListPageDTO : public PageDTO<HealthCertiListDTO::Wrapper>
{
	DTO_INIT(HealthCertiListPageDTO, PageDTO<HealthCertiListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_