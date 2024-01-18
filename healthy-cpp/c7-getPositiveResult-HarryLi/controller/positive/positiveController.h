#pragma once
#include "../../domain/vo/positive/positiveVO.h"
#include "../../domain/query/positive/positiveQuery.h"
#ifndef _POSITIVECONTROLLER_H_
#define _POSITIVECONTROLLER_H_

#include OATPP_CODEGEN_BEGIN(ApiController)
class PositiveConrtoller : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(PositiveConrtoller);
public:
	// 定义阳性结果查询接口描述
	ENDPOINT_INFO(queryPositive) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("positive.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PositiveListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		// 姓名
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("positive.filed.personname"), "LiMing", true);
		// 体检科室
		API_DEF_ADD_QUERY_PARAMS(String, "officeName", ZH_WORDS_GETTER("positive.filed.officename"), "001", false);
		// 体检日期
		API_DEF_ADD_QUERY_PARAMS(String, "checkDate", ZH_WORDS_GETTER("positive.filed.checkdate"), "2024-01-07", false);
		// 结果状态 是否正常 0为正常 1为不正常
		API_DEF_ADD_QUERY_PARAMS(UInt32, "isNormal", ZH_WORDS_GETTER("positive.filed.isNormal"), 1, false);

	}

	ENDPOINT(API_M_GET, "/positive/query-positive", queryPositive, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(positiveQuery, PositiveQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPositive(positiveQuery));
	}
private:
	PositiveListPageJsonVO::Wrapper execQueryPositive(const PositiveQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) 

#endif