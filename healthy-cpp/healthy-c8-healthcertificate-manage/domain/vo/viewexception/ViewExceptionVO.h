#pragma once
#ifndef _ViewExceptionVO_
#define _ViewExceptionVO_

#include "../../GlobalInclude.h"
#include "../../dto/viewexception/ViewExceptionDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ViewExceptionJsonVO : public JsonVO<ViewExceptionDTO::Wrapper> {
	DTO_INIT(ViewExceptionJsonVO, JsonVO<ViewExceptionDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ViewExceptionPageJsonVO : public JsonVO<ViewExceptionPageDTO::Wrapper> {
	DTO_INIT(ViewExceptionPageJsonVO, JsonVO<ViewExceptionPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_