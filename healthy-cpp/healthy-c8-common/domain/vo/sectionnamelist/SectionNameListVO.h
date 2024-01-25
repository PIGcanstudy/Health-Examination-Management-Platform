#pragma once
#ifndef _SectionNameListVO_
#define _SectionNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/sectionnamelist/SectionNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SectionNameListVO : public JsonVO<SectionNameListDTO::Wrapper> {
	DTO_INIT(SectionNameListVO, JsonVO<SectionNameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SectionNameListPageJsonVO : public JsonVO<SectionNameListPageDTO::Wrapper> {
	DTO_INIT(SectionNameListPageJsonVO, JsonVO<SectionNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_