#pragma once
#ifndef _IDDTO_H_
#define _IDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  查询id主键服务于删除、修改 传输数据对象实体
*/
class IdDTO : public oatpp::DTO
{
	DTO_INIT(IdDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("id.field.id"));
};

/**
*  查询id主键服务于删除、修改   分页数据实体
*/
class IdPageDTO : public PageDTO<IdDTO::Wrapper> {
	DTO_INIT(IdPageDTO, PageDTO<IdDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IDDTO_H_