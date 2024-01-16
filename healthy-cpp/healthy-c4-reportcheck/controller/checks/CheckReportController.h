#pragma once
#ifndef _REPORTCONTROLLER_H_
#define _REPORTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/checks/CheckReportQuery.h"
#include "domain/vo/checks/CheckReportVO.h"
#include "domain/dto/checks/CheckReportListDTO.h"

// 定义API控制器使用的宏
#include OATPP_CODEGEN_BEGIN(ApiController)

class CheckReportController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问接口
	API_ACCESS_DECLARE(CheckReportController);

public://定义接口
	// 定义分页查询接口描述
	ENDPOINT_INFO(queryCheckReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("check.get.summary"));
		//定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HENDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数描述
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckReportListPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 查询类型
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("Report.field.type"), "1", true);
		// 姓名
		API_DEF_ADD_QUERY_PARAMS(String, "person_name", ZH_WORDS_GETTER("Report.field.name"), "li ming", false);
		// 订单编号
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("Report.field.orderId"), "123456", false);
		// 体检编号
		API_DEF_ADD_QUERY_PARAMS(String, "test_num", ZH_WORDS_GETTER("Report.field.testNum"), "123", false);
		// 单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "unit_id", ZH_WORDS_GETTER("Report.field.unitId"), "huawei", false);
		// 是否过审
		API_DEF_ADD_QUERY_PARAMS(Boolean, "statu", ZH_WORDS_GETTER("Report.field.statu"), "1", false);
		// 是否复查
		API_DEF_ADD_QUERY_PARAMS(Boolean, "is_recheck", ZH_WORDS_GETTER("Report.field.isRecheck"), "1", false);
		// 体检日期
		API_DEF_ADD_QUERY_PARAMS(String, "check_date", ZH_WORDS_GETTER("Report.field.checkDate"), "20231209", false);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "checks/query-report", queryCheckReport, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(crq, CheckReportQuery, params);
		//呼叫执行函数响应
		API_HANDLER_RESP_VO(execCheckReport(crq));
	}
private://定义接口的执行函数
	CheckReportListPageJsonVO::Wrapper execCheckReport(const CheckReportQuery::Wrapper& query);
};

// 取消API控制器使用宏 
#include OATPP_CODEGEN_END(ApiController)// <- End Codegen
#endif // !_REPORTCONTROLLER_H_
