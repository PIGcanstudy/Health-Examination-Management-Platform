#pragma once
#ifndef _ADDNEWITEMSCONTROLLER_H_
#define _ADDNEWITEMSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"
#include "domain/vo/addNewItems/AddNewItemsVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ���������¼�������������ӿڵ�ʹ��
 */
class AddNewItemsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddNewItemsController);
	// 3 ����ӿ�
public:
	// 3.1 �����ҳ��ѯ���������¼�ӿ�����   ��ѯ��Review�н��У��˴�Ӧɾ��
	//ENDPOINT_INFO(queryAddNewItems) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addNewItems.query.summary"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(AddNewItemsPageJsonVO);
	//	// �����ҳ��ѯ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// ����������ѯ��������
	//	//������Ŀid
	//	API_DEF_ADD_QUERY_PARAMS(String, "checkProjectId", ZH_WORDS_GETTER("addNew.field.checkProjectId"), "aaaaa", false);
	//	//������Ŀ����
	//	API_DEF_ADD_QUERY_PARAMS(String, "checkProjectName", ZH_WORDS_GETTER("addNew.field.checkProjectName"), "bbb", false);
	//	//�����Ŀid
	//	API_DEF_ADD_QUERY_PARAMS(String, "portfolioProjectId", ZH_WORDS_GETTER("addNew.field.portfolioProjectId"), "aaaaa", false);
	//	//�����Ŀ����
	//	API_DEF_ADD_QUERY_PARAMS(String, "portfolioProjectName", ZH_WORDS_GETTER("addNew.field.portfolioProjectName"), "aaaaa", false);
	//	//����ԭ��
	//	API_DEF_ADD_QUERY_PARAMS(String, "reason", ZH_WORDS_GETTER("addNew.field.reason"), "fall ill", false);
	//}
	//// 3.2 �����ѯ�ӿڴ���
	//ENDPOINT(API_M_GET, "/review/query-addNewItems", queryAddNewItems, QUERIES(QueryParams, queryparams), API_HANDLER_AUTH_PARAME) {
	//	// ������ѯ����ΪQuery����ģ��
	//	API_HANDLER_QUERY_PARAM(userQuery, AddNewItemsQuery, queryparams);
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(execQueryAddNewItems(userQuery, authObject->getPayload()));
	//}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addAddNewItems) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addNewItems.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/review/post-addNewItems", addAddNewItems, BODY_DTO(AddNewItemsDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddAddNewItems(dto));
	}

private: //����ӿ�ִ�к���
	// 3.3 ��ҳ��ѯ����   ��ѯ��Review�н��У��˴�Ӧɾ��
	//AddNewItemsPageJsonVO::Wrapper execQueryAddNewItems(const AddNewItemsQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��������
	Uint64JsonVO::Wrapper execAddAddNewItems(const AddNewItemsDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //!_ADDNEWITEMSCONTROLLER_H_