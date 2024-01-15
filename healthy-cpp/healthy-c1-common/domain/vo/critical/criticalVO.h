#pragma once
#ifndef _CRITICALLISTVO_H_
#define _CRITICALLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/critical/CriticalDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO,������Ӧ�ͻ���Json����
 */
class CriticalListJsonVO : public JsonVO<CriticalListDTO::Wrapper>
{
	DTO_INIT(CriticalListJsonVO, JsonVO<CriticalListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_