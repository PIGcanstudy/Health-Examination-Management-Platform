#pragma once
#ifndef _GROUP_PERSON_CONTROLLER_
#define _GROUP_PERSON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GroupPersonController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GroupPersonController);
public: // 定义接口
	ENDPOINT_INFO(queryTest) {
		// 定义接口描述
		info->summary = ZH_WORDS_GETTER("test.get.summary");
		// 定义接口响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, params)) {
		// 将查询参数转换成PageQuery查询模型
		API_HANDLER_QUERY_PARAM(pq, PageQuery, params);
		// 执行业务逻辑处理
		API_HANDLER_RESP_VO(execQueryTest(pq));
	}
private: // 定义接口执行函数
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& pq);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GROUP_PERSON_CONTROLLER_