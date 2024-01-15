#pragma once

#ifndef _BASEPROJECT_VO_
#define _BASEPROJECT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/baseProject/BaseProjectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ŀ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaseProjectJsonVO : public JsonVO<BaseProjectDTO::Wrapper> {
	DTO_INIT(BaseProjectJsonVO, JsonVO<BaseProjectDTO::Wrapper>);
};

/**
 * ������Ŀ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaseProjectPageJsonVO : public JsonVO<BaseProjectPageDTO::Wrapper> {
	DTO_INIT(BaseProjectPageJsonVO, JsonVO<BaseProjectPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BASEPROJECT_VO_