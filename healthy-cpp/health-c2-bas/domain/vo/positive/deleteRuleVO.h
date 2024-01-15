#ifndef _deleteRule_VO_
#define _deleteRule_VO_

#include "../../GlobalInclude.h"
#include "../../dto/positive/resRuleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * JsonVOÊµÌå
 */
class deleteRuleJsonVO : public JsonVO<resRuleDTO::Wrapper>
{
	DTO_INIT(deleteRuleJsonVO, JsonVO<resRuleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_deleteRule_VO_