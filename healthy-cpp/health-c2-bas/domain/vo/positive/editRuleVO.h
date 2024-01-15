#ifndef _editRule_VO_
#define _editRule_VO_

#include "../../GlobalInclude.h"
#include "../../dto/positive/ruleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * JsonVOÊµÌå
 */
class editRuleJsonVO : public JsonVO<ruleDTO::Wrapper>
{
	DTO_INIT(editRuleJsonVO, JsonVO<ruleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_editRule_VO_