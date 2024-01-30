#pragma once

#ifndef _DOWNLOADSAMPLECODEVO_H_
#define _DOWNLOADSAMPLECODEVO_H_

#include "../GlobalInclude.h"
#include "../dto/downloadSampleCodeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * PDF上传结果数据
 */
class downloadSampleCodeVO : public JsonVO<downloadSampleCodeDTO::Wrapper>
{
	DTO_INIT(downloadSampleCodeVO, JsonVO<downloadSampleCodeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DOWNLOADSAMPLECODEVO_H_