#pragma once
#ifndef _SectionNameListVO_
#define _SectionNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/sectionnamelist/SectionNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class SectionNameListVO : public JsonVO<SectionNameListDTO::Wrapper> {
	DTO_INIT(SectionNameListVO, JsonVO<SectionNameListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class SectionNameListPageJsonVO : public JsonVO<SectionNameListPageDTO::Wrapper> {
	DTO_INIT(SectionNameListPageJsonVO, JsonVO<SectionNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_