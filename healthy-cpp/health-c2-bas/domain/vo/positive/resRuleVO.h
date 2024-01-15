#ifndef _resRule_VO_
#define _resRule_VO_

#include "../../GlobalInclude.h"
#include "../../dto/positive/resRuleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 结果规则JsonVO实体
 */
class resRuleJsonVO : public JsonVO<resRuleDTO::Wrapper>
{
	DTO_INIT(resRuleJsonVO, JsonVO<resRuleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_resRule_VO_