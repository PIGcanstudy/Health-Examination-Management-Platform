#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include "domain/query/unknownmodule/BasicInformationQuery.h"
#include "domain/query/unknownmodule/LifeHistoryQuery.h"
#include "domain/query/unknownmodule/PastMedicalHistoryQuery.h"
#include "domain/query/unknownmodule/ProfessionalHistoryQuery.h"

#include "domain/vo/unknownmodule/BasicInformationVO.h"
#include "domain/vo/unknownmodule/LifeHistoryVO.h"
#include "domain/vo/unknownmodule/PastMedicalHistoryVO.h"
#include "domain/vo/unknownmodule/ProfessionalHistoryVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class UnknownModuleController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(UnknownModuleController);
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryBasicInformation) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BasicInformationPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}
	ENDPOINT(API_M_GET, "/unknownmodule/queryBasicInformation", queryBasicInformation, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(biq, BasicInformationQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBasicInformation(biq));
	}

	/*************************************************************************************************************/

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryLifeHistory) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LifeHistoryPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}

	ENDPOINT(API_M_GET, "/unknownmodule/queryLifeHistory", queryLifeHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(biq, LifeHistoryQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryLifeHistory(biq));
	}

	/*************************************************************************************************************/

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryPastMedicalHistory) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PastMedicalHistoryPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}

	ENDPOINT(API_M_GET, "/unknownmodule/queryPastMedicalHistory", queryPastMedicalHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(biq, PastMedicalHistoryQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPastMedicalHistory(biq));
	}

	/*************************************************************************************************************/

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryProfessionalHistory) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProfessionalHistoryPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}

	ENDPOINT(API_M_GET, "/unknownmodule/queryProfessionalHistory", queryProfessionalHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(biq, ProfessionalHistoryQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProfessionalHistory(biq));
	}
	
private:
	BasicInformationPageJsonVO::Wrapper execQueryBasicInformation(const BasicInformationQuery::Wrapper& query);
	LifeHistoryPageJsonVO::Wrapper execQueryLifeHistory(const LifeHistoryQuery::Wrapper& query);
	PastMedicalHistoryPageJsonVO::Wrapper execQueryPastMedicalHistory(const PastMedicalHistoryQuery::Wrapper& query);
	ProfessionalHistoryPageJsonVO::Wrapper execQueryProfessionalHistory(const ProfessionalHistoryQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_