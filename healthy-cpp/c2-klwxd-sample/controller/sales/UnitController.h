#pragma once
#ifndef _UNITCONTROLLER_H_
#define _UNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/sales/UnitQuery.h"
#include "../../domain/vo/sales/UnitVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

//单位分页查询实体
class UnitController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(UnitController);

public://定义接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryUnit) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("unit.field.type"),1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("unit.field.name"), "z company", false);
		API_DEF_ADD_QUERY_PARAMS(String, "uscc", ZH_WORDS_GETTER("unit.field.uscc"), "lwwwwe", false);
		API_DEF_ADD_QUERY_PARAMS(String,"linkMan",ZH_WORDS_GETTER("unit.field.linkMan"),u8"快乐五香蛋",false);
		API_DEF_ADD_QUERY_PARAMS(String, "linkPhone", ZH_WORDS_GETTER("unit.field.linkPhone"),"189*****",false);
	}


	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/sales/query-unit",queryUnit, QUERIES(QueryParams,params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, UnitQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnit(uq));
	}

private://定义接口执行函数

	UnitListPageJsonVO::Wrapper execQueryUnit(const UnitQuery::Wrapper& query);

};


#include OATPP_CODEGEN_END(ApiController)

#endif