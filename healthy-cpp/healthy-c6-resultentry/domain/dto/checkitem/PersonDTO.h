#pragma once

#ifndef _PERSONDTO_H_
#define _PERSONDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��������Ŀ����������ݴ���ģ��
 */
class PersonDTO : public oatpp::DTO
{
	DTO_INIT(PersonDTO, DTO);
	//��Ա���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("checkitem.person.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONDTO_H_

