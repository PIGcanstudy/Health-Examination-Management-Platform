#ifndef _REPORTCONTROLLER_H_
#define _REPORTCONTROLLER_H_
#include"domain/vo/BaseJsonVO.h"
#include"../../domain/vo/generate_reports/ReportVO.h"
#include"../../domain/query/generate_reports/ReportQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ReportController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(ReportController);
public:
	ENDPOINT_INFO(reportCheck) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.title"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReportListPageDTO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//��ʼʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "begDate", ZH_WORDS_GETTER("unit.begDate"), "0000-00-00", false);
		//����ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("unit.endDate"), "0000-00-00", false);
		//��쵥λ
		API_DEF_ADD_QUERY_PARAMS(String, "phyUnit", ZH_WORDS_GETTER("unit.phyUnit"), "XXXXX", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/generate_report", reportCheck, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ReportQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execqueryReport(userQuery));
	}

private:
	ReportListPageDTOJsonVO::Wrapper ReportController::execqueryReport(const ReportQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif  
