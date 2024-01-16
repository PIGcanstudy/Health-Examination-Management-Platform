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
#ifndef _MEDICALEXAMINATIONREGISTRATIONDTO_H_
#define _MEDICALEXAMINATIONREGISTRATIONDTO_H_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 体检登记，点击新增后需要填写保存的信息
 */
class MedicalExaminationRegistrationDTO : public oatpp::DTO
{
	DTO_INIT(MedicalExaminationRegistrationDTO, DTO);
	// t_group_person
	// 体检编号【提交后系统自动生成】
	// 身份证号
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("registration.field.idCard"));
	// 姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("registration.field.personName"));
	// 性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("registration.field.sex"));
	// 年龄
	API_DTO_FIELD_DEFAULT(Int32, age, ZH_WORDS_GETTER("registration.field.age"));
	// 体检类型
	API_DTO_FIELD_DEFAULT(String, jcType, ZH_WORDS_GETTER("registration.field.jcType"));
	// 联系电话
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("registration.field.mobile"));
	// 单位名称
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("registration.field.workName"));
	// 婚姻状态
	API_DTO_FIELD_DEFAULT(String, isMarry, ZH_WORDS_GETTER("registration.field.isMarry"));
	// 分组名称【多表连接查询】
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("registration.field.groupId"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_MEDICALEXAMINATIONREGISTRATIONDTO_H_