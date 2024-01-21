#ifndef _REPORTLISTDTO_H_
#define _REPORTLISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class ReportListDTO : public oatpp::DTO
{
	DTO_INIT(ReportListDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("uint.id"));
	//������
	API_DTO_FIELD_DEFAULT(String, begDate, ZH_WORDS_GETTER("uint.begDate"));
	//���ʱ��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("uint.endDate"));
	//��쵥λ
	API_DTO_FIELD_DEFAULT(String, phyUnit, ZH_WORDS_GETTER("uint.phyUnit"));
};

/**
 * ʾ����ҳ�������
 */
class ReportListPageDTO : public PageDTO<ReportListDTO::Wrapper>
{
	DTO_INIT(ReportListPageDTO, PageDTO<ReportListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_