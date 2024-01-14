#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ɾ����ѯ����ʵ��
*/
class deleteRuleQuery : public PageQuery
{
	DTO_INIT(deleteQuery, DTO);
	// ����/��Ŀ����
	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("positive.resRules.field.projectName"));
	// ����
	API_DTO_FIELD_DEFAULT(String, condition, ZH_WORDS_GETTER("positive.resRules.field.condition"));
	// �ʺ��Ա�
	API_DTO_FIELD_DEFAULT(String, genderAppropriate, ZH_WORDS_GETTER("positive.resRules.field.genderAppropriate"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_