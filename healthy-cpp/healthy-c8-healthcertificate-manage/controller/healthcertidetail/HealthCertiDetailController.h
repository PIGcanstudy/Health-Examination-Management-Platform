#pragma once
#ifndef _HealthCertiDetailController_
#define _HealthCertiDetailController_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class HealthCertiDetailController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(HealthCertiDetailController);
public:
	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadHealthCertiDetail) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("healthcertidetail.download-healthcertidetail.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "pdfname", ZH_WORDS_GETTER("healthcertidetail.field.pdfname"), "", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/healthcertificate-manage/download-healthcertidetail", downloadHealthCertiDetail, QUERY(String, pdfname)) {
		return execDownloadHealthCertiDetail(pdfname);
	}

private: // 定义接口执行函数
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadHealthCertiDetail(const String& pdfname);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_