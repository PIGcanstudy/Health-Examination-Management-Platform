#pragma

#ifndef _COMMON_VO_
#define _COMMON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/common/CommonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取组合项目列表显示JsonVO，用于响应给客户端的Json对象
 */
class PackagesListJsonVO : public JsonVO<PackagesListDTO::Wrapper> {
	DTO_INIT(PackagesListJsonVO, JsonVO<PackagesListDTO::Wrapper>);
};

/**
 * 获取组合项目列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class PackagesListPageJsonVO : public JsonVO<PackagesListPageDTO::Wrapper> {
	DTO_INIT(PackagesListPageJsonVO, JsonVO<PackagesListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif