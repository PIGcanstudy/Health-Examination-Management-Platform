#pragma once
#ifndef _UesrNameListVO_
#define _UesrNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/uesrnamelist/UesrNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UesrNameListJsonVO : public JsonVO<UesrNameListDTO::Wrapper> {
	DTO_INIT(UesrNameListJsonVO, JsonVO<UesrNameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UesrNameListPageJsonVO : public JsonVO<UesrNameListPageDTO::Wrapper> {
	DTO_INIT(UesrNameListPageJsonVO, JsonVO<UesrNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_