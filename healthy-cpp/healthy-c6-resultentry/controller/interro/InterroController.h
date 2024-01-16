#pragma once
#ifndef _INTERRO_CONTROLLER_
#define _INTERRO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/interro/InterroQuery.h"
#include "domain/dto/interro/InterroDTO.h"
#include "domain/vo/interro/InterroVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
class InterroController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(InterroController);
public:
	ENDPOINT_INFO(queryInterro) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("interro.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InterroJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "id", ZH_WORDS_GETTER("interro.field.id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "project", ZH_WORDS_GETTER("interro.field.project"), "xxx", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c6-resultentry/Interro", queryInterro, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, InterroQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryInterro(userQuery, authObject->getPayload()));
	}
private:
	InterroJsonVO::Wrapper execQueryInterro(const InterroQuery::Wrapper& query, const PayloadDTO& payload);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _INTERRO_CONTROLLER_