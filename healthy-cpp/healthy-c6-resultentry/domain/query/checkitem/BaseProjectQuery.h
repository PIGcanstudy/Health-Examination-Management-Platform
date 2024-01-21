#pragma once
#ifndef _BASEPROJECT_H_
#define _BASEPROJECT_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*����һ����ѯ�����Ŀ�ڻ�����Ŀ������Ĵ���ģ��
*/

class BaseProjectQuery : public oatpp::DTO
{
	DTO_INIT(BaseProjectQuery, DTO);
	//��ѡ�������Ŀ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("checkitem.portfolio.name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASEPROJECT_H_
