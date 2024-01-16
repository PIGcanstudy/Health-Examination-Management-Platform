#pragma once
#ifndef _CRITICALDELETECONTROLLER_H_
#define _CRITICALDELETECONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/critical/CriticalDeleteVO.h"
#include "../../domain/query/critical/CriticalQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CriticalDeleteController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(CriticalDeleteController);
public:

	// ����Σ��ֵ�б��ѯ�ӿ�����
	ENDPOINT_INFO(queryDeleteCritical) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("critical.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CriticalDeleteListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
	}
	//����Σ��ֵ��ѯ�б�ӿ�
	ENDPOINT(API_M_DEL, "/critical/query-delete-critical", queryDeleteCritical, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(cq, CriticalQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDeleteCritical(cq));
		return createResponse(Status::CODE_200, "OK");
	}
private:
	//����ӿ�ִ�к���
	CriticalDeleteListJsonVO::Wrapper execDeleteCritical(const CriticalQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_
