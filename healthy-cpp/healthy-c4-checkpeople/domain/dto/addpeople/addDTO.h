#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _ADD_DTO_
#define _ADD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class AddDTO : public oatpp::DTO
{
	DTO_INIT(AddDTO, DTO);
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
	DTO_FIELD(Int64, age);
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

/**
 * 示例分页传输对象
 */
class AddPageDTO : public PageDTO<AddDTO::Wrapper>
{
	DTO_INIT(AddPageDTO, PageDTO<AddDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADD_DTO_