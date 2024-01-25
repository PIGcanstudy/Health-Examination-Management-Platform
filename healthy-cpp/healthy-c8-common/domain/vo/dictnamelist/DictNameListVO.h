#pragma once
#ifndef _DictNameListVO_
#define _DictNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/dictnamelist/DictNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DictNameListJsonVO : public JsonVO<DictNameListDTO::Wrapper> {
	DTO_INIT(DictNameListJsonVO, JsonVO<DictNameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DictNameListPageJsonVO : public JsonVO<DictNameListPageDTO::Wrapper> {
	DTO_INIT(DictNameListPageJsonVO, JsonVO<DictNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_