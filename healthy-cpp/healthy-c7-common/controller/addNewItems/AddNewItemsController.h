#pragma once
#ifndef _ADDNEWITEMSCONTROLLER_H_
#define _ADDNEWITEMSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"
#include "domain/vo/addNewItems/AddNewItemsVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AddNewItemsController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(AddNewItemsController);
public: //����ӿ�
	// 1 �����¼�б� �����ҳ��ѯ�����¼�ӿ�����
	ENDPOINT_INFO(queryAddNewItems) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addNewItems.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AddNewItemsPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//��ѡ��Ŀ
		API_DEF_ADD_QUERY_PARAMS(String, "projectsToBeSelected", ZH_WORDS_GETTER("addNewItems.field.projectsToBeSelected"), "aaaaa", false);
		//��ѡ��Ŀ
		API_DEF_ADD_QUERY_PARAMS(String, "selectedProjects", ZH_WORDS_GETTER("addNewItems.field.selectedProjects"), "bbb", false);
		//����ԭ��
		API_DEF_ADD_QUERY_PARAMS(String, "reason", ZH_WORDS_GETTER("addNewItems.field.reason"), "fall ill", false);

	}
	// 1 �����¼�б� �����ҳ��ѯ�����¼�ӿ�
	ENDPOINT(API_M_GET, "/review/query-AddNewItems", queryAddNewItems, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(rq, AddNewItemsQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAddNewItems(rq));
	}

private: //����ӿ�ִ�к���
	AddNewItemsPageJsonVO::Wrapper execQueryAddNewItems(const AddNewItemsQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //!_ADDNEWITEMSCONTROLLER_H_