#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 删除查询对象实体
*/
class deleteRuleQuery : public PageQuery
{
	DTO_INIT(deleteQuery, DTO);
	// 规则/项目名称
	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("positive.resRules.field.projectName"));
	// 条件
	API_DTO_FIELD_DEFAULT(String, condition, ZH_WORDS_GETTER("positive.resRules.field.condition"));
	// 适合性别
	API_DTO_FIELD_DEFAULT(String, genderAppropriate, ZH_WORDS_GETTER("positive.resRules.field.genderAppropriate"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_