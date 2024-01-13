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
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("qls_hep.get.summary"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("qls_hep.data.name"), ZH_WORDS_GETTER("qls_hep.example.name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "test_num", ZH_WORDS_GETTER("qls_hep.data.test_num"), ZH_WORDS_GETTER("qls_hep.example.test_num"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("qls_hep.data.dept"), ZH_WORDS_GETTER("qls_hep.example.dept"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "physical_type", ZH_WORDS_GETTER("qls_hep.data.physical_type"), ZH_WORDS_GETTER("qls_hep.example.physical_type"), false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "is_check", ZH_WORDS_GETTER("qls_hep.data.is_check"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "is_recheck", ZH_WORDS_GETTER("qls_hep.data.is_recheck"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_regist_date", ZH_WORDS_GETTER("qls_hep.data.start_regist_date"), ZH_WORDS_GETTER("qls_hep.example.start_regist_date"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "finish_regist_date", ZH_WORDS_GETTER("qls_hep.data.finish_regist_date"), ZH_WORDS_GETTER("qls_hep.example.finish_regist_date"), false);
	};

	ENDPOINT(API_M_GET, "/qls_hep", queryTest, QUERIES(QueryParams, params)) {
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