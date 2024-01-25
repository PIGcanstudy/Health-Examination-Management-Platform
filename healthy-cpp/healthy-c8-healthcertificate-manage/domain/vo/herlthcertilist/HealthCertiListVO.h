#pragma once
#ifndef _HealthCertiListVO_
#define _HealthCertiListVO_

#include "../../GlobalInclude.h"
#include "../../dto/herlthcertilist/HealthCertiListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class HealthCertiListJsonVO : public JsonVO<HealthCertiListDTO::Wrapper> {
	DTO_INIT(HealthCertiListJsonVO, JsonVO<HealthCertiListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class HealthCertiListPageJsonVO : public JsonVO<HealthCertiListPageDTO::Wrapper> {
	DTO_INIT(HealthCertiListPageJsonVO, JsonVO<HealthCertiListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_