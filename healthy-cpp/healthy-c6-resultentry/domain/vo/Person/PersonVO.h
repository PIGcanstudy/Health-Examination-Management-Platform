#pragma once
#ifndef _PERSON_VO_
#define _PERSON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Person/PersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class PersonJsonVO : public JsonVO<PersonDTO::Wrapper> {
	DTO_INIT(PersonJsonVO, JsonVO<PersonDTO::Wrapper>);
};

// ∑÷“≥’π æ
class PersonPageJsonVO : public JsonVO<PersonPageDTO::Wrapper> {
	DTO_INIT(PersonPageJsonVO, JsonVO<PersonPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PERSON_VO_