#pragma once
#ifndef _UploadMoreController_
#define _UploadMoreController_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class UploadMoreController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(UploadMoreController);
public:

	// 定义一个多文件上传接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("uploadmore.upload-more.summary"), uploadHealthCertiMore, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/healthcertificate-manage/upload-more", uploadHealthCertiMore, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadHealthCertiMore(request));

private: // 定义接口执行函数
	// 执行多文件上传处理
	StringJsonVO::Wrapper execUploadHealthCertiMore(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_