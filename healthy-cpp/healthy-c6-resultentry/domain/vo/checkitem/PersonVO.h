#pragma once
#ifndef _PERSONVO_H_
#define _PERSONVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/checkitem/PersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/*
*��λ�б���ʾJsonVOʵ��
*/
class PersonJsonVO : public JsonVO<PersonDTO::Wrapper> {
	DTO_INIT(PersonJsonVO, JsonVO<PersonDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONVO_H_
