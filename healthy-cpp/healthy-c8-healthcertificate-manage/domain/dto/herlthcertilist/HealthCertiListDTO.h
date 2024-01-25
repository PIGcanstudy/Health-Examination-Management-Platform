#pragma once
#ifndef _HealthCertiListDTO_
#define _HealthCertiListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class HealthCertiListDTO : public oatpp::DTO
{
	DTO_INIT(HealthCertiListDTO, DTO);
	//TODO : 页面要显示的东西

};

/**
 * 示例分页传输对象
 */
class HealthCertiListPageDTO : public PageDTO<HealthCertiListDTO::Wrapper>
{
	DTO_INIT(HealthCertiListPageDTO, PageDTO<HealthCertiListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_