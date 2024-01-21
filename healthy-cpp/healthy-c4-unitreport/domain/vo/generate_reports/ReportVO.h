#ifndef _REPORTVO_H_
#define _REPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/generate_reports/ReportListDTO .h"

#include OATPP_CODEGEN_BEGIN(DTO)

//��λ�б���ʾJsonVOʵ��
class ReportListJsonVO : public JsonVO<ReportListDTO::Wrapper> {
	DTO_INIT(ReportListJsonVO, JsonVO<ReportListDTO::Wrapper>);
};
//��λ�б��ҳ��ʾJsonVOʵ��
class ReportListPageDTOJsonVO : public JsonVO<ReportListPageDTO::Wrapper> {
	DTO_INIT(ReportListPageDTOJsonVO, JsonVO<ReportListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_#pragma once
