#pragma once
#ifndef _PlanProListDTO_
#define _PlanProListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PlanProListDTO : public oatpp::DTO
{
	DTO_INIT(PlanProListDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class PlanProListPageDTO : public PageDTO<PlanProListDTO::Wrapper>
{
	DTO_INIT(PlanProListPageDTO, PageDTO<PlanProListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 