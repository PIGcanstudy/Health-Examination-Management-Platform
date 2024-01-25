#pragma once
#ifndef _HealthCertiListController_
#define _HealthCertiListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/herlthcertilist/HealthCertiListQuery.h"
#include "domain/dto/herlthcertilist/HealthCertiListDTO.h"
#include "domain/vo/herlthcertilist/HealthCertiListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class HealthCertiListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(HealthCertiListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryHealthCertiList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("herlthcertilist.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(HealthCertiListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("herlthcertilist.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("herlthcertilist.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("herlthcertilist.field.sex"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "age", ZH_WORDS_GETTER("herlthcertilist.field.age"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "print_statu", ZH_WORDS_GETTER("herlthcertilist.field.print_statu"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "register_date", ZH_WORDS_GETTER("herlthcertilist.field.register_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "upload_statu", ZH_WORDS_GETTER("herlthcertilist.field.upload_statu"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/healthcertificate-manage/query-herlthcertilist", queryHealthCertiList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, HealthCertiListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryHealthCertiList(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	HealthCertiListPageJsonVO::Wrapper execQueryHealthCertiList(const HealthCertiListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_