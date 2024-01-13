#pragma once
#ifndef _GROUP_PERSON_CONTROLLER_
#define _GROUP_PERSON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GroupPersonController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(GroupPersonController);
public: // ����ӿ�
	ENDPOINT_INFO(queryTest) {
		// ����ӿ�����
		info->summary = ZH_WORDS_GETTER("test.get.summary");
		// ����ӿ���Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, params)) {
		// ����ѯ����ת����PageQuery��ѯģ��
		API_HANDLER_QUERY_PARAM(pq, PageQuery, params);
		// ִ��ҵ���߼�����
		API_HANDLER_RESP_VO(execQueryTest(pq));
	}
private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& pq);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GROUP_PERSON_CONTROLLER_