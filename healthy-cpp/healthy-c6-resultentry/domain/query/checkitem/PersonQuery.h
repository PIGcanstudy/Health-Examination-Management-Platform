#pragma once
#ifndef _PERSONPROJECT_H_
#define _PERSONPROJECT_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*����һ����ѯ�����Ա����������Ŀ������ݵĴ���ģ��
*/

class PersonQuery : public oatpp::DTO
{
	DTO_INIT(PersonQuery, DTO);
	//����
	//API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("checkitem.person.name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONPROJECT_H_