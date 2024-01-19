#pragma once
#ifndef _IDVO_H_
#define _IDVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/id/IdDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  查询id主键服务于删除、修改  显示JsonVO实体
*/
class IdJsonVO : public JsonVO<IdDTO::Wrapper> {
	DTO_INIT(IdJsonVO, JsonVO<IdDTO::Wrapper>);
};

/**
 * 查询id主键服务于删除、修改  显示分页JsonVO
 */
class IdPageJsonVO : public JsonVO<IdPageDTO::Wrapper> {
	DTO_INIT(IdPageJsonVO, JsonVO<IdPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IDVO_H_