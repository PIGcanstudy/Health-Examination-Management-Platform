#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: c1-pepper
 @Date: 2024/1/16

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
#ifndef _RULESLISTCONTROLLER_H_
#define _RULESLISTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/rules/RulesListQuery.h"
#include "domain/query/rules/RulesListPageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/rules/RulesListVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class RulesListController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(RulesListController);
public:
	// �����ѯ���й�����Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAllRules) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("rules.query-all.summary"), RulesListJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "shortname", ZH_WORDS_GETTER("rules.field.shortname"), "li ming", true);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/rules/query-all", queryAllRules, RulesListQuery, executeQueryAll(query));

	// �����޸��û���Ϣ�˵�����
	ENDPOINT_INFO(modifyRules) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("rules.modify-rules.summary"), StringJsonVO::Wrapper);
		// �����޸Ĳ�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("rules.field.age"), 100, false);
		API_DEF_ADD_QUERY_PARAMS(String, "shortname", ZH_WORDS_GETTER("rules.field.shortname"), "feifei", false);
		// ���������������ʽ������ѡ���ϴ��ļ�
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
	}
	// �����޸��û���Ϣ�˵㴦��ע�⣺�˷�ʽֻ֧�ֵ��ļ��ϴ������Ҹ����ֶβ��Ǻܶ�ĳ���ʹ�ã�
	ENDPOINT(API_M_POST, "/rules/modify-rules", modifyRules, BODY_STRING(String, fileBody), QUERIES(QueryParams, qps), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(dto, RulesListDTO, qps);
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(executeModifyRules(fileBody, dto));
	}

	// �����ѯ�û��˵��ӿڶ˵�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("rules.query-rules.summary"), queryRules, RulesListJsonVO::Wrapper);
	// �����ѯ�û��˵��ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/rules/query-rules", queryRules, executeQueryRules(authObject->getPayload()))
private:
	// ��ѯ����
	RulesListPageJsonVO::Wrapper executeQueryAll(const RulesListQuery::Wrapper& RulesListQuery);
	// �޸��û���Ϣ
	StringJsonVO::Wrapper executeModifyRules(const String& fileBody, const RulesListDTO::Wrapper& dto);
	// ���Բ˵�
	RulesListJsonVO::Wrapper executeQueryRules(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RULESLISTCONTROLLER_H_