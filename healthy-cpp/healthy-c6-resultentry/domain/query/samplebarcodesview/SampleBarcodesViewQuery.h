#ifndef _SAMPLEBARCODESVIEW_QUERY_
#define	_SAMPLEBARCODESVIEW_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 查询样本条码
*/
class SampleBarcodesViewQuery :public oatpp::DTO
{
	DTO_INIT(SampleBarcodesViewQuery, DTO);
	//体检人ID
	DTO_FIELD(String, person_id);
	DTO_FIELD_INFO(person_id) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.personid");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLEBARCODESVIEW_QUERY_

