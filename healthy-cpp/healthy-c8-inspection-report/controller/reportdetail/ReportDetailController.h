#pragma once
#ifndef _ReportDetailController_
#define _ReportDetailController_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class ReportDetailController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ReportDetailController);
public:
	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadReportDetail) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("reportdetail.download-reportdetail.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "pdfname", ZH_WORDS_GETTER("reportdetail.field.pdfname"), "", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/inspection-report/download-reportdetail", downloadReportDetail, QUERY(String, pdfname)) {
		return execDownloadReportDetail(pdfname);
	}

private: // 定义接口执行函数
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadReportDetail(const String& pdfname);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_