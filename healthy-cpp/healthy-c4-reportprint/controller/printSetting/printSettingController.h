#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 13:05:04

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
#ifndef _printSetting_CONTROLLER_H_
#define _printSetting_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printSettingQuery.h"
#include "domain/dto/printSettingDTO.h"
#include "domain/vo/printSettingVO.h"

// 0 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**

 */
class printSettingController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 
	API_ACCESS_DECLARE(printSettingController);
	// 3 
public:
	// 3.1 
	ENDPOINT_INFO(queryprintSetting) {
		// 
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("printSetting.get.printview"));
		// 
		API_DEF_ADD_AUTH();
		// 
		API_DEF_ADD_RSP_JSON_WRAPPER(printSettingJsonVO);
		// 
		API_DEF_ADD_QUERY_PARAMS(String, "papersize", ZH_WORDS_GETTER("printSetting.field.papersize"), "A4", true);
		API_DEF_ADD_QUERY_PARAMS(String, "pagerange", ZH_WORDS_GETTER("printSetting.field.pagerange"), "1-4", true);
		API_DEF_ADD_QUERY_PARAMS(String, "DoubleSidedOrNot", ZH_WORDS_GETTER("printSetting.field.pagerange"), "yes", true);
	}
	// 3.2 
	ENDPOINT(API_M_GET, "/printSetting", queryprintSetting, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 
		API_HANDLER_QUERY_PARAM(uq, printSettingQuery, params);
		// 
		API_HANDLER_RESP_VO(execQueryprintSetting(uq));
	}

private:

	printSettingJsonVO::Wrapper execQueryprintSetting(const printSettingQuery::Wrapper& query);
};

// 
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _printSetting_CONTROLLER_H_