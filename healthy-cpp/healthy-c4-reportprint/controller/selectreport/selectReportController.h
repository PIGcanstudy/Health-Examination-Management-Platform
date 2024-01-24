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
#ifndef _selectREPORT_CONTROLLER_H_
#define _selectREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/selectReportQuery.h"
#include "domain/dto/selectReportDTO.h"
#include "domain/vo/selectReportVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ�����Ա��ѯ�ӿ�
 * �����ˣ�����
 */
class selectReportController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(selectReportController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryselectReport) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("select.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(selectReportJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

		// ����
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("select.field.name"), "li ming", true);
		// �������
		API_DEF_ADD_QUERY_PARAMS(String, "downloadpath", ZH_WORDS_GETTER("setting.field.downloadpath"), "12", false);
		// �����
		API_DEF_ADD_QUERY_PARAMS(String, "testNum", ZH_WORDS_GETTER("select.field.testNum"), "11", false);
		// ��λ����
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("select.field.dept"), "wuih", false);
		// �������
		API_DEF_ADD_QUERY_PARAMS(String, "checkDate", ZH_WORDS_GETTER("select.field.checkDate"), "20231209", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/select", queryselectReport, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, selectReportQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryselectReport(uq));
	}

private:
	
	selectReportPageJsonVO::Wrapper execQueryselectReport(const selectReportQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _selectREPORT_CONTROLLER_H_