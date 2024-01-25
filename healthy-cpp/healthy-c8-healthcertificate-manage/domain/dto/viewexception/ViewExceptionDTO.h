#pragma once
#ifndef _ViewExceptionDTO_
#define _ViewExceptionDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ViewExceptionDTO : public oatpp::DTO
{
	DTO_INIT(ViewExceptionDTO, DTO);
	//TODO : 页面要显示的东西

};

/**
 * 示例分页传输对象
 */
class ViewExceptionPageDTO : public PageDTO<ViewExceptionDTO::Wrapper>
{
	DTO_INIT(ViewExceptionPageDTO, PageDTO<ViewExceptionDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_