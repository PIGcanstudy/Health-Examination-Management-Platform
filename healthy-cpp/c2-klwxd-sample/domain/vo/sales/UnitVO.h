#pragma once
#ifndef _UNITVO_H_
#define _UNITVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/sales/UnitListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//单位列表显示jsonVO实体
class UnitListJsonVO : public JsonVO <UnitListDTO::Wrapper>
{
	DTO_INIT(UnitListJsonVO, JsonVO <UnitListDTO::Wrapper>);
};

//单位列表表示分页JsonVO实体
class UnitListPageJsonVO :public JsonVO <UnitListPageDTO::Wrapper>
{
	DTO_INIT(UnitListPageJsonVO, JsonVO <UnitListPageDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif