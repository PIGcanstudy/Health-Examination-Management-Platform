#ifndef _REPORTLISTDTO_H_
#define _REPORTLISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ReportListDTO : public oatpp::DTO
{
	DTO_INIT(ReportListDTO, DTO);
	//唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("uint.id"));
	//报告编号
	API_DTO_FIELD_DEFAULT(String, begDate, ZH_WORDS_GETTER("uint.begDate"));
	//体检时间
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("uint.endDate"));
	//体检单位
	API_DTO_FIELD_DEFAULT(String, phyUnit, ZH_WORDS_GETTER("uint.phyUnit"));
};

/**
 * 示例分页传输对象
 */
class ReportListPageDTO : public PageDTO<ReportListDTO::Wrapper>
{
	DTO_INIT(ReportListPageDTO, PageDTO<ReportListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_