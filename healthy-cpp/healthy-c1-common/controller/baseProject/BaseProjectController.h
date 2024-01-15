#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _BASEPROJECT_CONTROLLER_
#define _BASEPROJECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/baseProject/BaseProjectQuery.h"
#include "domain/dto/baseProject/BaseProjectDTO.h"
#include "domain/vo/baseProject/BaseProjectVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class BaseProjectController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(BaseProjectController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryBaseProject) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("baseProject.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BaseProjectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("baseProject.field.name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("baseProject.field.sex"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/baseProject", queryBaseProject, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, BaseProjectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryBaseProject(userQuery, authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addBaseProject) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("baseProject.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/baseProject", addBaseProject, BODY_DTO(BaseProjectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddBaseProject(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("baseProject.put.summary"), modifyBaseProject, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/baseProject", modifyBaseProject, BODY_DTO(BaseProjectDTO::Wrapper, dto), execModifyBaseProject(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeBaseProject) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("baseProject.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("baseProject.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/baseProject/{id}", removeBaseProject, PATH(UInt64, id), execRemoveBaseProject(id));

	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryOne) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("baseProject.query-one.summary"), BaseProjectJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("baseProject.field.id"), 1, true);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/baseProject/query-one", queryOne, QUERY(UInt64, id), execQueryOne(id, authObject->getPayload()));

	// 3.1 �����������ʽ������õĽӿ�2����
	ENDPOINT_INFO(queryAll) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("baseProject.query-all.summary"), BaseProjectPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("baseProject.field.name"), "li ming", false);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/baseProject/query-all", queryAll, BaseProjectQuery, execQueryAll(query, authObject->getPayload()));
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	BaseProjectPageJsonVO::Wrapper execQueryBaseProject(const BaseProjectQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddBaseProject(const BaseProjectDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyBaseProject(const BaseProjectDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveBaseProject(const UInt64& id);
	// 3.3 ��������ʽ�������1
	BaseProjectJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	// 3.3 ��������ʽ�������2
	BaseProjectPageJsonVO::Wrapper execQueryAll(const BaseProjectQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _BASEPROJECT_CONTROLLER_