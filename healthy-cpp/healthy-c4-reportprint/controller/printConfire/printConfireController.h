#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 13:05:04

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
#ifndef _printConfire_CONTROLLER_H_
#define _printConfire_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printConfireQuery.h"
#include "domain/dto/printConfireDTO.h"
#include "domain/vo/printConfireVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * ��������PDF���棬�����ѡ�񲿷�
 * �����ˣ����
 */
class printConfireController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 ����������������
	API_ACCESS_DECLARE(printConfireController);

	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryprintConfire) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("confire.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(printConfireJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

		// ����������ѯ��������
		// ��ӡ������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "reportId", ZH_WORDS_GETTER("confire.field.reportId"), 12345678, true);
		// ��ӡ��������
		API_DEF_ADD_QUERY_PARAMS(String, "reportName", ZH_WORDS_GETTER("confire.field.reportName"), "01 Star Cheak Reoprt", false);
		// �Ƿ��ӡ
		API_DEF_ADD_QUERY_PARAMS(Boolean, "isPrint", ZH_WORDS_GETTER("printSetting.field.isPrint"), true, true);
		// ��ӡ���״̬
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("printSetting.field.status"), "finished", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/confire", queryprintConfire, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, printConfireQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryprintConfire(uq));
	}

private:
	
	printConfirePageJsonVO::Wrapper execQueryprintConfire(const printConfireQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _printConfire_CONTROLLER_H_