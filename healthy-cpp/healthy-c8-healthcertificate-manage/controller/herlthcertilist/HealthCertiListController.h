#pragma once
#ifndef _HealthCertiListController_
#define _HealthCertiListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/herlthcertilist/HealthCertiListQuery.h"
#include "domain/dto/herlthcertilist/HealthCertiListDTO.h"
#include "domain/vo/herlthcertilist/HealthCertiListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class HealthCertiListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(HealthCertiListController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryHealthCertiList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("herlthcertilist.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(HealthCertiListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("herlthcertilist.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("herlthcertilist.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("herlthcertilist.field.sex"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "age", ZH_WORDS_GETTER("herlthcertilist.field.age"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "print_statu", ZH_WORDS_GETTER("herlthcertilist.field.print_statu"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "register_date", ZH_WORDS_GETTER("herlthcertilist.field.register_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "upload_statu", ZH_WORDS_GETTER("herlthcertilist.field.upload_statu"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/healthcertificate-manage/query-herlthcertilist", queryHealthCertiList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, HealthCertiListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryHealthCertiList(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	HealthCertiListPageJsonVO::Wrapper execQueryHealthCertiList(const HealthCertiListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_