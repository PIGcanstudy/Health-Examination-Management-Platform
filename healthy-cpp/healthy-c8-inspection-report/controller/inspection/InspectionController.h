#pragma once

#ifndef _INSPECTION_CONTROLLER_
#define _INSPECTION_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/inspection/InspectionQuery.h"
#include "domain/dto/inspection/InspectionDTO.h"
#include "domain/vo/inspection/InspectionVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class InspectionController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(InspectionController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryReportList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inspection.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReportListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
			//�����
		API_DEF_ADD_PATH_PARAMS(String, "test_num", ZH_WORDS_GETTER("inspection.field.test_num"), "", false);
			//��쵥λ
		API_DEF_ADD_PATH_PARAMS(String, "physical_unit", ZH_WORDS_GETTER("inspection.field.physical_unit"), "", false);
			//���֤��
		API_DEF_ADD_PATH_PARAMS(String, "id_card", ZH_WORDS_GETTER("inspection.field.id_card"), "", false);
			//�������
		API_DEF_ADD_PATH_PARAMS(String, "check_date", ZH_WORDS_GETTER("inspection.field.check_date"), "", false);
			//���״̬
		API_DEF_ADD_PATH_PARAMS(Int32, "statu", ZH_WORDS_GETTER("inspection.field.statu"), 0, true);
			//����
		API_DEF_ADD_PATH_PARAMS(String, "person_name", ZH_WORDS_GETTER("inspection.field.person_name"), "", false);
			//�Ա�
		API_DEF_ADD_PATH_PARAMS(String, "sex", ZH_WORDS_GETTER("inspection.field.sex"), "", false);
			//����
		API_DEF_ADD_PATH_PARAMS(Int32, "age", ZH_WORDS_GETTER("inspection.field.age"),0,false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/inspection/report-list", queryReportList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(reportList, ReportListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryReportList(reportList, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ReportListPageJsonVO::Wrapper execQueryReportList(const ReportListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif