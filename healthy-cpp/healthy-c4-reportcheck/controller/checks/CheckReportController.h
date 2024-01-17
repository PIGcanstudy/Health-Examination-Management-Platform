#pragma once
#ifndef _REPORTCONTROLLER_H_
#define _REPORTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/checks/CheckReportQuery.h"
#include "domain/vo/checks/CheckReportVO.h"
#include "domain/dto/checks/CheckReportListDTO.h"

// ����API������ʹ�õĺ�
#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* �ӿڵ�ʵ��
* ������ Z
*/
class CheckReportController : public oatpp::web::server::api::ApiController
{
	// ������������ʽӿ�
	API_ACCESS_DECLARE(CheckReportController);

public://����ӿ�
	// �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryCheckReport) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("check.get.summary"));
		//����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HENDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckReportListPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// ��ѯ����
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("Report.field.type"), nullptr, true);
		// ����
		API_DEF_ADD_QUERY_PARAMS(String, "person_name", ZH_WORDS_GETTER("Report.field.name"), nullptr, false);
		// �������
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("Report.field.orderId"), nullptr, false);
		// �����
		API_DEF_ADD_QUERY_PARAMS(String, "test_num", ZH_WORDS_GETTER("Report.field.testNum"), nullptr, false);
		// ��λ����
		API_DEF_ADD_QUERY_PARAMS(String, "unit_id", ZH_WORDS_GETTER("Report.field.unitId"), nullptr, false);
		// �Ƿ����
		API_DEF_ADD_QUERY_PARAMS(Boolean, "statu", ZH_WORDS_GETTER("Report.field.statu"), "", true);
		// �Ƿ񸴲�
		API_DEF_ADD_QUERY_PARAMS(Boolean, "is_recheck", ZH_WORDS_GETTER("Report.field.isRecheck"), "", true);
		// ��ʼ����
		API_DEF_ADD_QUERY_PARAMS(String, "stardate", ZH_WORDS_GETTER("Report.field.starDate"), "2023-12-17", true);
		// ��������
		API_DEF_ADD_QUERY_PARAMS(String, "enddate", ZH_WORDS_GETTER("Report.field.endDate"), "2024-1-17", true);
	}
	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "checks/query-report", queryCheckReport, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//������ѯ����ΪQuery����ģ��,Ҳ���ǰѲ�ѯ������ֵ����
		API_HANDLER_QUERY_PARAM(crq, CheckReportQuery, params);
		//����ִ�к�����Ӧ
		API_HANDLER_RESP_VO(execCheckReport(crq));
	}
private://����ӿڵ�ִ�к���
	CheckReportListPageJsonVO::Wrapper execCheckReport(const CheckReportQuery::Wrapper& query);
};

// ȡ��API������ʹ�ú� 
#include OATPP_CODEGEN_END(ApiController)// <- End Codegen
#endif // !_REPORTCONTROLLER_H_
