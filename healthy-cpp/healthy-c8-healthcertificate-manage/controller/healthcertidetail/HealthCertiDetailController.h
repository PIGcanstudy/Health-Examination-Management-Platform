#pragma once
#ifndef _HealthCertiDetailController_
#define _HealthCertiDetailController_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class HealthCertiDetailController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(HealthCertiDetailController);
public:
	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadHealthCertiDetail) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("healthcertidetail.download-healthcertidetail.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "pdfname", ZH_WORDS_GETTER("healthcertidetail.field.pdfname"), "", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/healthcertificate-manage/download-healthcertidetail", downloadHealthCertiDetail, QUERY(String, pdfname)) {
		return execDownloadHealthCertiDetail(pdfname);
	}

private: // ����ӿ�ִ�к���
	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadHealthCertiDetail(const String& pdfname);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_