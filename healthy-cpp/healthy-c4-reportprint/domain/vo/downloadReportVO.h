#pragma once

#ifndef _DOWNLOADREPORTVO_H_
#define _DOWNLOADREPORTVO_H_

#include "../GlobalInclude.h"
#include "../dto/downloadReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * PDF上传结果数据
 */
class downloadReportVO : public JsonVO<downloadReportDTO::Wrapper>
{
	DTO_INIT(downloadReportVO, JsonVO<downloadReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DOWNLOADREPORTVO_H_