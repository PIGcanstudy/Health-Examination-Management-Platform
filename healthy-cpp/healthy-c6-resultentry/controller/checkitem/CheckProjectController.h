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
#ifndef _CHECKPROJECT_CONTROLLER_
#define _CHECKPROJECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/checkitem/CheckProjectVO.h"
#include "../../domain/query/checkitem/CheckProjectQuery.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CheckProjectController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(CheckProjectController);
public:	//����ӿ�

	//�����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryCheckProject) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("checkitem.query.projectsummary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckProjectJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "combo_name", ZH_WORDS_GETTER("checkitem.checkproject.combo_name"), ZH_WORDS_GETTER("checkitem.checkproject.eg_cn"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "comboitem_name", ZH_WORDS_GETTER("checkitem.checkproject.comboitem_name"), ZH_WORDS_GETTER("checkitem.checkproject.eg_cin"), false);
	}

	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "checkitem/query-checkproject", queryCheckProject, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(cpq, CheckProjectQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCheckProject(cpq));
	}

private:	//����ӿ�ִ�к���
	CheckProjectJsonVO::Wrapper execQueryCheckProject(const CheckProjectQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CHECKPROJECT_CONTROLLER_