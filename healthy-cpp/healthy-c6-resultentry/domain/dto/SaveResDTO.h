#pragma once
#ifndef _SAVERES_DTO_
#define _SAVERES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class SaveResDTO : public oatpp::DTO
{
	DTO_INIT(SaveResDTO, DTO);
	// 编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER(""));
	// 
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVERES_DTO_