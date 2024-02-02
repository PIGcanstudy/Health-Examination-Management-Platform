#pragma once
#ifndef _UPLOADMOREDTO_
#define _UPLOADMOREDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报告审核传输对象
 */
class UploadMoreDTO : public oatpp::DTO
{
	DTO_INIT(UploadMoreDTO, DTO);
	// 健康证文件名
	DTO_FIELD(String, fileName);
	DTO_FIELD_INFO(fileName) {
		info->description = ZH_WORDS_GETTER("uploadmore.field.fileName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 