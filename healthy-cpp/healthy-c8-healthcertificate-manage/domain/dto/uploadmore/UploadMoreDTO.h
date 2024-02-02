#pragma once
#ifndef _UPLOADMOREDTO_
#define _UPLOADMOREDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������˴������
 */
class UploadMoreDTO : public oatpp::DTO
{
	DTO_INIT(UploadMoreDTO, DTO);
	// ����֤�ļ���
	DTO_FIELD(String, fileName);
	DTO_FIELD_INFO(fileName) {
		info->description = ZH_WORDS_GETTER("uploadmore.field.fileName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 