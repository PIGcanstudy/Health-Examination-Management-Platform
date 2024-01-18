#pragma once
#include "../../domain/vo/positive/positiveVO.h"
#include "../../domain/query/positive/positiveQuery.h"
#ifndef _POSITIVECONTROLLER_H_
#define _POSITIVECONTROLLER_H_

#include OATPP_CODEGEN_BEGIN(ApiController)
class PositiveConrtoller : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(PositiveConrtoller);
public:
	// �������Խ����ѯ�ӿ�����
	ENDPOINT_INFO(queryPositive) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("positive.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PositiveListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

		// ����
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("positive.filed.personname"), "LiMing", true);
		// ������
		API_DEF_ADD_QUERY_PARAMS(String, "officeName", ZH_WORDS_GETTER("positive.filed.officename"), "001", false);
		// �������
		API_DEF_ADD_QUERY_PARAMS(String, "checkDate", ZH_WORDS_GETTER("positive.filed.checkdate"), "2024-01-07", false);
		// ���״̬ �Ƿ����� 0Ϊ���� 1Ϊ������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "isNormal", ZH_WORDS_GETTER("positive.filed.isNormal"), 1, false);

	}

	ENDPOINT(API_M_GET, "/positive/query-positive", queryPositive, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(positiveQuery, PositiveQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPositive(positiveQuery));
	}
private:
	PositiveListPageJsonVO::Wrapper execQueryPositive(const PositiveQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) 

#endif