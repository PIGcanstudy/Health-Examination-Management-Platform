#pragma once
#ifndef _UNITVO_H_
#define _UNITVO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnitJsonVO : public oatpp::DTO
{
	DTO_INIT(UnitVO, DTO);
};

class UnitListPageJsonVO : public JsonVO<UnitListPageDTO::Wrapper>
{
	DTO_INIT(UnitListPageJsonVO, JsonVO<UnitListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITVO_H_