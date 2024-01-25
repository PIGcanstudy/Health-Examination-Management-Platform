#pragma once
#ifndef _PrintMoreDTO_
#define _PrintMoreDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PrintMoreDTO : public oatpp::DTO
{
	DTO_INIT(PrintMoreDTO, DTO);
	//列表

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_