#pragma once
#ifndef _PlanNameListDTO_
#define _PlanNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PlanNameListDTO : public oatpp::DTO
{
	DTO_INIT(PlanNameListDTO, DTO);
};

/**
 * ʾ����ҳ�������
 */
class PlanNameListPageDTO : public PageDTO<PlanNameListDTO::Wrapper>
{
	DTO_INIT(PlanNameListPageDTO, PageDTO<PlanNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 