#pragma

#ifndef _COMMON_VO_
#define _COMMON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/common/CommonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�����Ŀ�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PackagesListJsonVO : public JsonVO<PackagesListDTO::Wrapper> {
	DTO_INIT(PackagesListJsonVO, JsonVO<PackagesListDTO::Wrapper>);
};

/**
 * ��ȡ�����Ŀ�б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PackagesListPageJsonVO : public JsonVO<PackagesListPageDTO::Wrapper> {
	DTO_INIT(PackagesListPageJsonVO, JsonVO<PackagesListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif