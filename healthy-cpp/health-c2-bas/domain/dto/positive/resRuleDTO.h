#ifndef _RESRULE_DTO_
#define _RESRULE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ������������ݶ���ʵ��
 */
class resRuleDTO : public oatpp::DTO
{
	DTO_INIT(resRuleDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.resRules.field.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, condition, ZH_WORDS_GETTER("positive.resRules.field.condition"));
	// �ʺ��Ա�
	API_DTO_FIELD_DEFAULT(String, genderAppropriate, ZH_WORDS_GETTER("positive.resRules.field.genderAppropriate"));
	//����Id
	API_DTO_FIELD_DEFAULT(String, positiveId, ZH_WORDS_GETTER("positive.resRules.field.positiveId"));
	// ����
	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("positive.resRules.field.projectName"));
	// �ж�����
	API_DTO_FIELD_DEFAULT(String, judgmentCondition, ZH_WORDS_GETTER("positive.resRules.field.judgmentCondition"));
	// �ų����Խ��
	API_DTO_FIELD_DEFAULT(String, excludePositive, ZH_WORDS_GETTER("positive.resRules.field.excludePositive"));
	// ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("positive.resRules.field.type"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RESRULE_DTO_