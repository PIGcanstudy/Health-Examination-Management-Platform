#pragma once
#ifndef _IDCONTROLLER_H_
#define _IDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/id/IdQuery.h"
#include "domain/dto/id/IdDTO.h"
#include "domain/vo/id/IdVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class IdController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(IdController);
public: //����ӿ�
	// 1 �����¼�б� �����ҳ��ѯ�����¼�ӿ�����
	ENDPOINT_INFO(queryId) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("id.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(IdPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//��ѡ��Ŀ
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("id.field.id"), "0001", false);
		
	}
	// 1 �����¼�б� �����ҳ��ѯ�����¼�ӿ�
	ENDPOINT(API_M_GET, "/review/query-Id", queryId, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(rq, IdQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryId(rq));
	}

private: //����ӿ�ִ�к���
	IdPageJsonVO::Wrapper execQueryId(const IdQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //!_IDCONTROLLER_H_