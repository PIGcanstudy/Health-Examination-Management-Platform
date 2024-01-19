#ifndef _SAMPLEBARCODESVIEW_VO_
#define _SAMPLEBARCODESVIEW_VO_
#include "../../GlobalInclude.h"
#include"../healthy-c6-resultentry/domain/dto/samplebarcodesview/SampleBarcodesViewDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
* Ñù±¾ÌõÂëJsonVO
*/
class SampleBarcodesViewJsonVO : public JsonVO<oatpp::List<SampleBarcodesViewDTO::Wrapper>> {
	DTO_INIT(SampleBarcodesViewJsonVO, JsonVO< oatpp::List<SampleBarcodesViewDTO::Wrapper>>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLEBARCODESVIEW_VO_
