#pragma once
#ifndef _UesrNameListVO_
#define _UesrNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/uesrnamelist/UesrNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class UesrNameListJsonVO : public JsonVO<UesrNameListDTO::Wrapper> {
	DTO_INIT(UesrNameListJsonVO, JsonVO<UesrNameListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class UesrNameListPageJsonVO : public JsonVO<UesrNameListPageDTO::Wrapper> {
	DTO_INIT(UesrNameListPageJsonVO, JsonVO<UesrNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_