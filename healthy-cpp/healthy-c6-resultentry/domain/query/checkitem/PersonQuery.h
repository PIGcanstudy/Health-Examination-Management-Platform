#pragma once
#ifndef _PERSONPROJECT_H_
#define _PERSONPROJECT_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*定义一个查询体检人员参与的组合项目体检数据的传输模型
*/

class PersonQuery : public oatpp::DTO
{
	DTO_INIT(PersonQuery, DTO);
	//姓名
	//API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("checkitem.person.name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONPROJECT_H_