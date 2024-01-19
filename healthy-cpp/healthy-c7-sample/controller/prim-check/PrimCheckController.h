#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-18

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
#ifndef _PRIMCHECKCONTROLLER_H_
#define _PRIMCHECKCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/query/prim-check/PrimCheckQuery.h"
#include"../../domain/dto/prim-check/PrimCheckListDTO.h"
#include"../../domain/dto/prim-check/PrimCheckDetailDTO.h"
#include"../../domain/vo/prim-check/PrimCheckVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PrimCheckController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(PrimCheckController);
public: //定义接口

	//1.1项目结论查询接口描述
	ENDPOINT_INFO(queryPrimCheck) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("primCheck.query.list"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PrimCheckListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//人员ID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("primCheck.field.personId"),"007",true);
	}
	//1.2项目结论查询接口处理
	ENDPOINT(API_M_GET,"/primary-check/depart-result",queryPrimCheck,QUERIES(QueryParams,params),API_HANDLER_AUTH_PARAME)
	{  
		// 解析查询参数为Query领域模型（接收Browser层的Query）
		API_HANDLER_QUERY_PARAM(resultQuery, PrimCheckQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPrimCheck(resultQuery));
	}

	//2.1项目结论详情查询接口描述
	ENDPOINT_INFO(queryPrimCheckDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("primCheck.query.detail"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PrimCheckDetailPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//人员ID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("primCheck.field.personId"), "007", true);
		//组合项目
		API_DEF_ADD_QUERY_PARAMS(String, "orderGroupItemId", ZH_WORDS_GETTER("primCheck.field.orderGroupItemId"),"madrid",true);
	}
	//2.2项目结论详情查询接口处理
	ENDPOINT(API_M_GET, "/primary-check/depart-item-result", queryPrimCheckDetail, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型（接收Browser层的参数，换成自己定义的Query类）
		API_HANDLER_QUERY_PARAM(resultQuery, PrimCheckQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPrimCheckDetail(resultQuery));
	}
private: //定义接口执行函数
	PrimCheckListPageJsonVO::Wrapper execQueryPrimCheck(const PrimCheckQuery::Wrapper& query);
	PrimCheckDetailPageJsonVO::Wrapper execQueryPrimCheckDetail(const PrimCheckQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PRIMCHECKCONTROLLER_H_