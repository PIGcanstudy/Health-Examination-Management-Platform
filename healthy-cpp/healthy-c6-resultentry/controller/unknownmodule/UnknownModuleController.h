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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include "domain/query/unknownmodule/BasicInformationQuery.h"
#include "domain/query/unknownmodule/LifeHistoryQuery.h"
#include "domain/query/unknownmodule/PastMedicalHistoryQuery.h"
#include "domain/query/unknownmodule/ProfessionalHistoryQuery.h"

#include "domain/vo/unknownmodule/BasicInformationVO.h"
#include "domain/vo/unknownmodule/LifeHistoryVO.h"
#include "domain/vo/unknownmodule/PastMedicalHistoryVO.h"
#include "domain/vo/unknownmodule/ProfessionalHistoryVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class UnknownModuleController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UnknownModuleController);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryBasicInformation) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BasicInformationPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}
	ENDPOINT(API_M_GET, "/unknownmodule/queryBasicInformation", queryBasicInformation, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(biq, BasicInformationQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryBasicInformation(biq));
	}

	/*************************************************************************************************************/

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryLifeHistory) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LifeHistoryPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}

	ENDPOINT(API_M_GET, "/unknownmodule/queryLifeHistory", queryLifeHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(biq, LifeHistoryQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryLifeHistory(biq));
	}

	/*************************************************************************************************************/

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPastMedicalHistory) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PastMedicalHistoryPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}

	ENDPOINT(API_M_GET, "/unknownmodule/queryPastMedicalHistory", queryPastMedicalHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(biq, PastMedicalHistoryQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPastMedicalHistory(biq));
	}

	/*************************************************************************************************************/

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProfessionalHistory) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodule.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProfessionalHistoryPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodule.field.personId"), "personId", false);
	}

	ENDPOINT(API_M_GET, "/unknownmodule/queryProfessionalHistory", queryProfessionalHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(biq, ProfessionalHistoryQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProfessionalHistory(biq));
	}
	
private:
	BasicInformationPageJsonVO::Wrapper execQueryBasicInformation(const BasicInformationQuery::Wrapper& query);
	LifeHistoryPageJsonVO::Wrapper execQueryLifeHistory(const LifeHistoryQuery::Wrapper& query);
	PastMedicalHistoryPageJsonVO::Wrapper execQueryPastMedicalHistory(const PastMedicalHistoryQuery::Wrapper& query);
	ProfessionalHistoryPageJsonVO::Wrapper execQueryProfessionalHistory(const ProfessionalHistoryQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_