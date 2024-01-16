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
#ifndef _CHECKPROJECT_CONTROLLER_
#define _CHECKPROJECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/checkitem/CheckProjectVO.h"
#include "../../domain/query/checkitem/CheckProjectQuery.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CheckProjectController : public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(CheckProjectController);
public:	//定义接口

	//定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryCheckProject) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("checkitem.query.projectsummary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckProjectJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "combo_name", ZH_WORDS_GETTER("checkitem.checkproject.combo_name"), ZH_WORDS_GETTER("checkitem.checkproject.eg_cn"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "comboitem_name", ZH_WORDS_GETTER("checkitem.checkproject.comboitem_name"), ZH_WORDS_GETTER("checkitem.checkproject.eg_cin"), false);
	}

	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "checkitem/query-checkproject", queryCheckProject, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(cpq, CheckProjectQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCheckProject(cpq));
	}

private:	//定义接口执行函数
	CheckProjectJsonVO::Wrapper execQueryCheckProject(const CheckProjectQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CHECKPROJECT_CONTROLLER_