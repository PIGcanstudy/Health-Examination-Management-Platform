#pragma once
#ifndef _ViewExceptionVO_
#define _ViewExceptionVO_

#include "../../GlobalInclude.h"
#include "../../dto/viewexception/ViewExceptionDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ViewExceptionJsonVO : public JsonVO<ViewExceptionDTO::Wrapper> {
	DTO_INIT(ViewExceptionJsonVO, JsonVO<ViewExceptionDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ViewExceptionPageJsonVO : public JsonVO<ViewExceptionPageDTO::Wrapper> {
	DTO_INIT(ViewExceptionPageJsonVO, JsonVO<ViewExceptionPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_