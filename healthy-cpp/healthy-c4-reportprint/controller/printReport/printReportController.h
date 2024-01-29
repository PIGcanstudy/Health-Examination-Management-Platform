#pragma once

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
	// ����һ�������ӡȷ�Ͻӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("print.get.print"), modifyprintReport, Uint64JsonVO::Wrapper);
	// ����ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/printConfire", modifyprintReport, BODY_DTO(printReportDTO::Wrapper, dto), execModifyprintReport(dto));


	// ����һ�����������ȡ�ӿ�
	// ��������
	ENDPOINT_INFO(downloadFile) {
		// �ӿڱ���
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("print.get.sampleCode"), Void);
		// ������
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeNum", ZH_WORDS_GETTER("addition.field.sampleCodeNum"), "436591946372", false);
		// ��������
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeName", ZH_WORDS_GETTER("addition.field.sampleCodeName"), ZH_WORDS_GETTER("addition.test.sampleCodeName"), false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/downloadSampleCode", downloadFile, QUERY(String, sampleCodeName)) {
		return execDownloadSampleCode(sampleCodeName);
	}

private:
	// �����ӡ 
	StringJsonVO::Wrapper execModifyprintReport(const printReportDTO::Wrapper& dto);
	// ��ȡ��������
	std::shared_ptr<OutgoingResponse> execDownloadSampleCode(const String& sampleCodeName);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTREPORT_CONTROLLER_H_