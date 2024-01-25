#pragma once
#ifndef _PlanProListVO_
#define _PlanProListVO_

#include "../../GlobalInclude.h"
#include "../../dto/planprolist/PlanProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PlanProListVO : public JsonVO<PlanProListDTO::Wrapper> {
	DTO_INIT(PlanProListVO, JsonVO<PlanProListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PlanProListPageJsonVO : public JsonVO<PlanProListPageDTO::Wrapper> {
	DTO_INIT(PlanProListPageJsonVO, JsonVO<PlanProListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_