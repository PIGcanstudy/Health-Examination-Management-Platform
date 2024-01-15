#pragma once
#ifndef _CRITICALCONTROLLER_H_
#define _CRITICALCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/critical/criticalVO.h"
#include "../../domain/query/critical/CriticalQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CriticalController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(CriticalController);
public:

	// ����Σ��ֵ�б��ѯ�ӿ�����
	ENDPOINT_INFO(queryCritical) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("critical.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CriticalListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "level", ZH_WORDS_GETTER("critical.field.level"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("critical.field.type"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "intervalValue", ZH_WORDS_GETTER("critical.field.intervalValue"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "allowSex", ZH_WORDS_GETTER("critical.field.allowSex"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "minAge", ZH_WORDS_GETTER("critical.field.minAge"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "maxAge", ZH_WORDS_GETTER("critical.field.maxAge"), 1, true);
	}
	//����Σ��ֵ��ѯ�б�ӿ�
	ENDPOINT(API_M_GET, "/critical/query-critical", queryCritical, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) 
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(cq, CriticalQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCritical(cq));
	}
private:
	//����ӿ�ִ�к���
	CriticalListJsonVO::Wrapper execQueryCritical(const CriticalQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_