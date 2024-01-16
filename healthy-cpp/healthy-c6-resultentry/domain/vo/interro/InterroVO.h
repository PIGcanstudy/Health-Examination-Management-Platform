#pragma once
#ifndef _INTERRO_VO_
#define _INTERRO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/interro/InterroDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class InterroJsonVO : public JsonVO<InterroDTO::Wrapper> {
	DTO_INIT(InterroJsonVO, JsonVO<InterroDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INTERRO_VO_