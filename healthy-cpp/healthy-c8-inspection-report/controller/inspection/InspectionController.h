#pragma once

#ifndef _INSPECTION_CONTROLLER_
#define _INSPECTION_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/inspection/InspectionQuery.h"
#include "domain/dto/inspection/InspectionDTO.h"
#include "domain/vo/inspection/InspectionVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class InspectionController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(InspectionController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryReportList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inspection.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReportListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
			//体检编号
		API_DEF_ADD_PATH_PARAMS(String, "test_num", ZH_WORDS_GETTER("inspection.field.test_num"), "", false);
			//体检单位
		API_DEF_ADD_PATH_PARAMS(String, "physical_unit", ZH_WORDS_GETTER("inspection.field.physical_unit"), "", false);
			//身份证号
		API_DEF_ADD_PATH_PARAMS(String, "id_card", ZH_WORDS_GETTER("inspection.field.id_card"), "", false);
			//体检日期
		API_DEF_ADD_PATH_PARAMS(String, "check_date", ZH_WORDS_GETTER("inspection.field.check_date"), "", false);
			//审核状态
		API_DEF_ADD_PATH_PARAMS(Int32, "statu", ZH_WORDS_GETTER("inspection.field.statu"), 0, true);
			//姓名
		API_DEF_ADD_PATH_PARAMS(String, "person_name", ZH_WORDS_GETTER("inspection.field.person_name"), "", false);
			//性别
		API_DEF_ADD_PATH_PARAMS(String, "sex", ZH_WORDS_GETTER("inspection.field.sex"), "", false);
			//年龄
		API_DEF_ADD_PATH_PARAMS(Int32, "age", ZH_WORDS_GETTER("inspection.field.age"),0,false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/inspection/report-list", queryReportList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(reportList, ReportListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryReportList(reportList, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	ReportListPageJsonVO::Wrapper execQueryReportList(const ReportListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif