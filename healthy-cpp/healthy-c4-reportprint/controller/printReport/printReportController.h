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
#ifndef _PRINTREPORT_CONTROLLER_H_
#define _PRINTREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printReportQuery.h"
#include "domain/dto/printReportDTO.h"
#include "domain/vo/printReportVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * ��ӡPDF����
 */
class printReportController : public oatpp::web::server::api::ApiController // 1 
{
	// ����������������
	API_ACCESS_DECLARE(printReportController);

	// ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryprintReport) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("print.get.print"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(printReportJsonVO);

		// ����������ѯ��������
		// ����ӡ�ı�����
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("preview.field.reportNum"), "1202204010001", false);
		// ��ӡ״̬
		API_DEF_ADD_QUERY_PARAMS(String, "printState", ZH_WORDS_GETTER("print.field.printState"), "finished", false);
		// Ŀ���ӡ��
		API_DEF_ADD_QUERY_PARAMS(String, "targetPrinter", ZH_WORDS_GETTER("print.field.targetPrinter"), "save as PDF", false);
		// ҳ��
		API_DEF_ADD_QUERY_PARAMS(String, "page", ZH_WORDS_GETTER("print.field.page"), "all", false);
		// ÿ���������ҳ��
		API_DEF_ADD_QUERY_PARAMS(UInt16, "pageNumPerTable", ZH_WORDS_GETTER("print.field.pageNumPerTable"), 1, false);
		// �Ƿ��ӡ��������
		API_DEF_ADD_QUERY_PARAMS(Boolean, "printSampleCode", ZH_WORDS_GETTER("print.field.printSampleCode"), false, false);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/printReport", queryprintReport, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, printReportQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryprintReport(uq));
	}

	// ����һ�����������ȡ�ӿ�
	// ��������
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeNum", ZH_WORDS_GETTER("addition.sampleCodeNum"), "123456", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/sampleCode/download", downloadFile, QUERY(String, sampleCodeNum)) {
		return execDownloadFile(sampleCodeNum);
	}

private:
	// �����ӡ 
	printReportPageJsonVO::Wrapper execQueryprintReport(const printReportQuery::Wrapper& query);
	// ��ȡ��������
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& sampleCodeNum);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTREPORT_CONTROLLER_H_