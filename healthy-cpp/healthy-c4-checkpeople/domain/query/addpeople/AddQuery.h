#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _ADD_QUERY_
#define _ADD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class AddQuery : public PageQuery
{
	DTO_INIT(AddQuery, PageQuery);
	//姓名、性别、证件号码、生日、年龄、是否婚配、手机号码
	DTO_FIELD(String, person_name);
	DTO_FIELD_INFO(person_name) {
		info->description = ZH_WORDS_GETTER("unit.field.personName");
	}
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("unit.field.Sex");
	}
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("unit.field.idCard");
	}
	DTO_FIELD(String, birth);
	DTO_FIELD_INFO(birth) {
		info->description = ZH_WORDS_GETTER("unit.field.Birth");
	}
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("unit.field.Age");
	}
	DTO_FIELD(String, is_marry);
	DTO_FIELD_INFO(is_marry) {
		info->description = ZH_WORDS_GETTER("unit.field.isMarry");
	}
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("unit.field.Mobile");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADD_QUERY_