#pragma once
#ifndef _HealthCertiListVO_
#define _HealthCertiListVO_

#include "../../GlobalInclude.h"
#include "../../dto/herlthcertilist/HealthCertiListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class HealthCertiListJsonVO : public JsonVO<HealthCertiListDTO::Wrapper> {
	DTO_INIT(HealthCertiListJsonVO, JsonVO<HealthCertiListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class HealthCertiListPageJsonVO : public JsonVO<HealthCertiListPageDTO::Wrapper> {
	DTO_INIT(HealthCertiListPageJsonVO, JsonVO<HealthCertiListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_