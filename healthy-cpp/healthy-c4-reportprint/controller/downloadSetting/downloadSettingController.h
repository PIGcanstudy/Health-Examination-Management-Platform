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
#ifndef _downloadSetting_CONTROLLER_H_
#define _downloadSetting_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/downloadSettingQuery.h"
#include "domain/dto/downloadSettingDTO.h"
#include "domain/vo/downloadSettingVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 批量下载PDF报告，报告的下载设置部分
 * 负责人：晚风
 */
class downloadSettingController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 
	API_ACCESS_DECLARE(downloadSettingController);
	// 3 
public:
	// 3.1 
	ENDPOINT_INFO(querydownloadSetting) {
		// 
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("downloadSetting.get.view"));
		// 
		API_DEF_ADD_AUTH();
		// 
		API_DEF_ADD_RSP_JSON_WRAPPER(downloadSettingJsonVO);
		// 
		API_DEF_ADD_QUERY_PARAMS(UInt64, "personId", ZH_WORDS_GETTER("downloadSetting.field.personId"),123456, true);
		//
		API_DEF_ADD_QUERY_PARAMS(UInt64, "reportNum", ZH_WORDS_GETTER("downloadSetting.field.reportNum"), 12, true);
		//
		API_DEF_ADD_QUERY_PARAMS(String, "downloadpath", ZH_WORDS_GETTER("downloadSetting.field.downloadpath"), "/usr", true);
	}
	// 3.2 
	ENDPOINT(API_M_GET, "/downloadSetting", querydownloadSetting, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 
		API_HANDLER_QUERY_PARAM(uq, downloadSettingQuery, params);
		// 
		API_HANDLER_RESP_VO(execQuerydownloadSetting(uq));
	}

private:

	downloadSettingJsonVO::Wrapper execQuerydownloadSetting(const downloadSettingQuery::Wrapper& query);
};

// 
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _downloadSetting_CONTROLLER_H_