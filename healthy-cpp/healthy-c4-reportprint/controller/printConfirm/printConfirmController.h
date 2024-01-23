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
#ifndef _PRINTCONFIRM_CONTROLLER_H_
#define _PRINTCONFIRM_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printConfirmQuery.h"
#include "domain/dto/printConfirmDTO.h"
#include "domain/vo/printConfirmVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * ��������PDF���棬�����ѡ�񲿷�
 * �����ˣ����
 */
class printConfirmController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 ����������������
	API_ACCESS_DECLARE(printConfirmController);

	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryprintConfirm) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("confirm.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(printConfirmJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

		// ����������ѯ��������
		// ��ӡ������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "printReportId", ZH_WORDS_GETTER("confirm.field.printReportId"), 12345678, true);
		// ��ӡ��������
		API_DEF_ADD_QUERY_PARAMS(String, "printReportName", ZH_WORDS_GETTER("confirm.field.printReportName"), "01 Star Cheak Reoprt", false);
		// �Ƿ��ӡ
		API_DEF_ADD_QUERY_PARAMS(Boolean, "isPrint", ZH_WORDS_GETTER("confirm.field.isPrint"), true, true);
		// ��ӡ���״̬
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("confirm.field.status"), "finished", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/confirm", queryprintConfirm, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, printConfirmQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryprintConfirm(uq));
	}

private:
	
	printConfirmPageJsonVO::Wrapper execQueryprintConfirm(const printConfirmQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTCONFIRM_CONTROLLER_H_