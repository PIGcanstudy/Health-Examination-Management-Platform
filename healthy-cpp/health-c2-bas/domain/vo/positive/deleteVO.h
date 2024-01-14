#ifndef _UNITVO_H_
#define _UNITVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/positive/deleteRuleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * JsonVOÊµÌå
 */
class deleteRuleJsonVO : public JsonVO<deleteRuleDTO::Wrapper>
{
	DTO_INIT(deleteRuleJsonVO, JsonVO<deleteRuleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITVO_H_