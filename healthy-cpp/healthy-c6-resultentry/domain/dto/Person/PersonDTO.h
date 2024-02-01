#pragma once
#ifndef _PERSON_DTO_
#define _PERSON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PersonDTO : public oatpp::DTO
{
	DTO_INIT(PersonDTO, DTO);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("person.data.name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("person.data.sex");
	}
	// ����
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("person.data.age");
	}
	// �������
	DTO_FIELD(String, physical_type);
	DTO_FIELD_INFO(physical_type) {
		info->description = ZH_WORDS_GETTER("person.data.physical_type");
	}
	// �Ƿ��������
	DTO_FIELD(UInt32, sporadic_physical);
	DTO_FIELD_INFO(sporadic_physical) {
		info->description = ZH_WORDS_GETTER("person.data.sporadic_physical");
	}
};

class PersonPageDTO : public PageDTO<PersonDTO::Wrapper>
{
	DTO_INIT(PersonPageDTO, PageDTO<PersonDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSON_DTO_