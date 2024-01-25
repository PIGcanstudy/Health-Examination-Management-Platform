#pragma once
#ifndef _PackageProNameListVO_
#define _PackageProNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/packagepronamelist/PackageProNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PackageProNameListJsonVO : public JsonVO<PackageProNameListDTO::Wrapper> {
	DTO_INIT(PackageProNameListJsonVO, JsonVO<PackageProNameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PackageProNameListPageJsonVO : public JsonVO<PackageProNameListPageDTO::Wrapper> {
	DTO_INIT(PackageProNameListPageJsonVO, JsonVO<PackageProNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_