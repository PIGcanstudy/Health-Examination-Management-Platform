#pragma once

#ifndef _PRINTREPORT_VO_
#define _PRINTREPORT_VO_

#include "../GlobalInclude.h"
#include "../dto/printReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class printReportJsonVO : public JsonVO<printReportDTO::Wrapper> {
	DTO_INIT(printReportJsonVO, JsonVO<printReportDTO::Wrapper>);
};

class printReportPageJsonVO : public JsonVO<printReportPageDTO::Wrapper> {
	DTO_INIT(printReportPageJsonVO, JsonVO<printReportPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PRINTREPORTS_VO_