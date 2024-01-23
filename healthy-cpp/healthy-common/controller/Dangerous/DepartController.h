#pragma once
#ifdef _DEPARTCONTROLLER_H_
#define _DEPARTCONTROLLER_H_

#include "domain\vo\BaseJsonVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class DepartController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(DepartController);
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryDepart) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("depart.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DepartListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//体检人员ID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("depart.field.officeName"),"0a",false);
	
	}

	ENDPOINT(API_M_GET, "/Dangerous/query-depart", queryDepart, QUERIES(QueryParams), API_HANDLER_AUTH_PARAME);
	// 解析查询参数为Query领域模型
	API_HANDLER_QUERY_PARAM(qd, queryDepart, queryParams);
	// 呼叫执行函数响应结果
	API_HANDLER_RESP_VO(execQueryDepart(qd));
private:
	DepartListPageJsonVO::Wrapper execQueryDepart(const DepartQuery::Wrapper& query);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_