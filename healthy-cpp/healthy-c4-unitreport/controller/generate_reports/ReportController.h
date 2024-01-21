#ifndef _REPORTCONTROLLER_H_
#define _REPORTCONTROLLER_H_
#include"domain/vo/BaseJsonVO.h"
#include"../../domain/vo/generate_reports/ReportVO.h"
#include"../../domain/query/generate_reports/ReportQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ReportController : public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(ReportController);
public:
	ENDPOINT_INFO(reportCheck) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReportListPageDTO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//开始时间
		API_DEF_ADD_QUERY_PARAMS(String, "begDate", ZH_WORDS_GETTER("unit.begDate"), "0000-00-00", false);
		//结束时间
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("unit.endDate"), "0000-00-00", false);
		//体检单位
		API_DEF_ADD_QUERY_PARAMS(String, "phyUnit", ZH_WORDS_GETTER("unit.phyUnit"), "XXXXX", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/generate_report", reportCheck, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ReportQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execqueryReport(userQuery));
	}

private:
	ReportListPageDTOJsonVO::Wrapper ReportController::execqueryReport(const ReportQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif  
