/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "AddPeopleService.h"
#include "../../dao/addpeople/AddPeopleDAO.h"




uint64_t AddPeopleService::saveData(const AddDTO::Wrapper& dto)
{
	// 组装DO数据
	AddDO data;
	data.setpersonName(dto->person_name.getValue(""));
	data.setSex(dto->sex.getValue(""));
	data.setAge(dto->age.getValue(1));
	data.setBirth(dto->birth.getValue(""));
	data.setidCard(dto->id_card.getValue(""));
	data.setisMarry(dto->is_marry.getValue(""));
	data.setMobile(dto->mobile.getValue(""));
	//DTO转DO
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, personName, person_name);
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, Sex, sex);
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, Age, age);
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, Birth, birth);
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, idCard, id_card);
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, isMarry, is_marry);
	ZO_STAR_DOMAIN_FILED_DTO_TO_DO(data, dto, Mobile, mobile);

	// 执行数据添加
	AddPeopleDAO dao;
	return dao.insert(data);
}

