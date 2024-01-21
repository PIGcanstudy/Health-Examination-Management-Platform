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
#ifndef _selectREPORT_CONTROLLER_H_
#define _selectREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/selectReportQuery.h"
#include "domain/dto/selectReportDTO.h"
#include "domain/vo/selectReportVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * 批量下载PDF报告，报告的选择部分
 * 负责人：晚风
 */
class selectReportController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 
	API_ACCESS_DECLARE(selectReportController);
	// 3 
public:
	// 3.1 
	ENDPOINT_INFO(queryselectReport) {
		// 
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("select.get.summary"));
		// 
		API_DEF_ADD_AUTH();
		// 
		API_DEF_ADD_RSP_JSON_WRAPPER(selectReportJsonVO);
		// 
		API_DEF_ADD_PAGE_PARAMS();
		// 

		// 
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("select.field.name"), "li ming", true);
		// 
		API_DEF_ADD_QUERY_PARAMS(String, "downloadpath", ZH_WORDS_GETTER("setting.field.downloadpath"), "12", false);
		// 
		API_DEF_ADD_QUERY_PARAMS(String, "testNum", ZH_WORDS_GETTER("select.field.testNum"), "11", false);
		// 
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("select.field.dept"), "wuih", false);
		// 
		API_DEF_ADD_QUERY_PARAMS(String, "checkDate", ZH_WORDS_GETTER("select.field.checkDate"), "20231209", false);
	}
	// 3.2 
	ENDPOINT(API_M_GET, "/select", queryselectReport, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// 
		API_HANDLER_QUERY_PARAM(uq, selectReportQuery, params);
		// 
		API_HANDLER_RESP_VO(execQueryselectReport(uq));
	}

private:
	
	selectReportPageJsonVO::Wrapper execQueryselectReport(const selectReportQuery::Wrapper& query);
};

// 
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _selectREPORT_CONTROLLER_H_