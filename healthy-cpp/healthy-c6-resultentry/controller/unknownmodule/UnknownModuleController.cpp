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
#include "UnknownModuleController.h"
#include "../../service/unknownmodule/BasicInformationService.h"
#include "../../service/unknownmodule/LifeHistoryService.h"
#include "../../service/unknownmodule/PastMedicalHistoryService.h"
#include "../../service/unknownmodule/ProfessionalHistoryService.h"


BasicInformationPageJsonVO::Wrapper UnknownModuleController::execQueryBasicInformation(const BasicInformationQuery::Wrapper& query) {
	// 定义一个Service
	BasicInformationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = BasicInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

LifeHistoryPageJsonVO::Wrapper UnknownModuleController::execQueryLifeHistory(const LifeHistoryQuery::Wrapper& query) {
	// 定义一个Service
	LifeHistoryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LifeHistoryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

PastMedicalHistoryPageJsonVO::Wrapper UnknownModuleController::execQueryPastMedicalHistory(const PastMedicalHistoryQuery::Wrapper& query) {
	// 定义一个Service
	PastMedicalHistoryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PastMedicalHistoryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProfessionalHistoryPageJsonVO::Wrapper UnknownModuleController::execQueryProfessionalHistory(const ProfessionalHistoryQuery::Wrapper& query) {
	// 定义一个Service
	ProfessionalHistoryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProfessionalHistoryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}