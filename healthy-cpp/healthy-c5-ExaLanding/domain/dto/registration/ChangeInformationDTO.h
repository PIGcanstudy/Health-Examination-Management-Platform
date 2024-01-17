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
#ifndef _CHANGEINFORMATIONDTO_H_
#define _CHANGEINFORMATIONDTO_H_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 体检登记，点击修改信息后需要保存的信息
 */
class ChangeInformationDTO : public oatpp::DTO
{
	DTO_INIT(ChangeInformationDTO, DTO);
	// t_group_person
	// 必填：
	// 人员姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("registration.changeInformation.personName"));
	// 性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("registration.changeInformation.sex"));
	// 年龄
	API_DTO_FIELD_DEFAULT(Int32, age, ZH_WORDS_GETTER("registration.changeInformation.age"));
	// 结婚状况
	API_DTO_FIELD_DEFAULT(String, isMarry, ZH_WORDS_GETTER("registration.changeInformation.isMarry"));
	// 证件号码
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("registration.changeInformation.idCard"));
	// 出生日期【datetime , 用什么类型】
	API_DTO_FIELD_DEFAULT(String, birth, ZH_WORDS_GETTER("registration.changeInformation.birth"));
	// 分组【多表连接查询】
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("registration.changeInformation.groupId"));
	
	// 非必填：
	// 单位名称
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("registration.changeInformation.workName"));
	// 手机号码
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("registration.changeInformation.mobile"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_CHANGEINFORMATIONDTO_H_