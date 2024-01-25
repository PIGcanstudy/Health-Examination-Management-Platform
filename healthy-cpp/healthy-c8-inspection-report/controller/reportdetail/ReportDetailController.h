#pragma once
#ifndef _ReportDetailController_
#define _ReportDetailController_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class ReportDetailController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ReportDetailController);
public:
	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadReportDetail) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("reportdetail.download-reportdetail.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "pdfname", ZH_WORDS_GETTER("reportdetail.field.pdfname"), "", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/inspection-report/download-reportdetail", downloadReportDetail, QUERY(String, pdfname)) {
		return execDownloadReportDetail(pdfname);
	}

private: // ����ӿ�ִ�к���
	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadReportDetail(const String& pdfname);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_