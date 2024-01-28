#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _UNITLISTDTO_H_
#define _UNITLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	单位列表传输数据对象实体——不分页的数据实体
*/
class UnitListDTO : public oatpp::DTO
{
	
	//定义字段
	DTO_INIT(UnitListDTO, DTO);
	//唯一编号
	/*姓名 person_name性别 sex证件号码  id_card出生日期 birth年龄 age是否结婚 is_marry手机号码 mobile*/
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unit.field.personName"));
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unit.field.sex"));
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(String, birth, ZH_WORDS_GETTER("unit.field.birth"));
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unit.field.age"));
	API_DTO_FIELD_DEFAULT(String, isMarry, ZH_WORDS_GETTER("unit.field.isMarry"));
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unit.field.mobile"));
};

/*
	单位分页列表传输数据对象实体——分页的数据实体
*/
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper>
{
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNITLISTDTO_H_