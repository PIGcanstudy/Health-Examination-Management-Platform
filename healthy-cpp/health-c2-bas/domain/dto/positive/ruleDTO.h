#ifndef _RULE_DTO_
#define _RULE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���������ݶ���ʵ��
 */
class ruleDTO : public oatpp::DTO
{
	DTO_INIT(ruleDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.rules.field.id"));
	// ��Ŀ����
	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("positive.rules.field.projectName"));
	// ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("positive.rules.field.type"));
	//����ֵ
	API_DTO_FIELD_DEFAULT(String, regularValue, ZH_WORDS_GETTER("positive.rules.field.regularValue"));
	// ���Թ���Id
	API_DTO_FIELD_DEFAULT(String, positiveResultsId, ZH_WORDS_GETTER("positive.rules.field.positiveResultsId"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RULE_DTO_