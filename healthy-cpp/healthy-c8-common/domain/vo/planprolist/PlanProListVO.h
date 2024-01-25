#pragma once
#ifndef _PlanProListVO_
#define _PlanProListVO_

#include "../../GlobalInclude.h"
#include "../../dto/planprolist/PlanProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PlanProListVO : public JsonVO<PlanProListDTO::Wrapper> {
	DTO_INIT(PlanProListVO, JsonVO<PlanProListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PlanProListPageJsonVO : public JsonVO<PlanProListPageDTO::Wrapper> {
	DTO_INIT(PlanProListPageJsonVO, JsonVO<PlanProListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_