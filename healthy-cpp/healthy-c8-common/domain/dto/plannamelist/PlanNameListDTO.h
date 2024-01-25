#pragma once
#ifndef _PlanNameListDTO_
#define _PlanNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PlanNameListDTO : public oatpp::DTO
{
	DTO_INIT(PlanNameListDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class PlanNameListPageDTO : public PageDTO<PlanNameListDTO::Wrapper>
{
	DTO_INIT(PlanNameListPageDTO, PageDTO<PlanNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 