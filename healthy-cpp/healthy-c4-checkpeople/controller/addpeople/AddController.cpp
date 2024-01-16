/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "AddController.h"
#include "../../service/addpeople/AddPeopleService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper AddController::execAddPeople(const AddDTO::Wrapper& dto)
{
	//响应客户端的json数据对象
	auto jvo = Uint64JsonVO::createShared();
	//参数检验
	//1、非空检验
	if (!dto->age || !dto->birth || !dto->id_card || !dto->is_marry || !dto->mobile || !dto->person_name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 有效值校验
	if ( dto->age < 0 || dto->person_name->empty() || dto->sex->empty() || dto->birth->empty() || dto->id_card->empty() ||
		dto->is_marry->empty() || dto->mobile->empty() )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	AddPeopleService service;
	//执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0){
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
