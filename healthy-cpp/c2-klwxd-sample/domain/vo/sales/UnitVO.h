#pragma once
#ifndef _UNITVO_H_
#define _UNITVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/sales/UnitListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//��λ�б���ʾjsonVOʵ��
class UnitListJsonVO : public JsonVO <UnitListDTO::Wrapper>
{
	DTO_INIT(UnitListJsonVO, JsonVO <UnitListDTO::Wrapper>);
};

//��λ�б��ʾ��ҳJsonVOʵ��
class UnitListPageJsonVO :public JsonVO <UnitListPageDTO::Wrapper>
{
	DTO_INIT(UnitListPageJsonVO, JsonVO <UnitListPageDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif