#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:19:05

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
#ifndef _DOWNLOADREPORT_CONTROLLER_H_
#define _DOWNLOADREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include "domain/vo/downloadReportVO.h"

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作接口
 */
class downloadReportController  : public oatpp::web::server::api::ApiController 
{
	//  定义控制器访问入口
	API_ACCESS_DECLARE(downloadReportController);

public:
	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		// 定义描述
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("print.get.download"), Void);
		// 待下载的报告编号
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("preview.field.reportNum"), "1202204010001", true);
	}

	// 定义端点
	ENDPOINT(API_M_GET, "/file/download", downloadFile, QUERY(String, id)) {
		return execDownloadFile(id);
	}

private: // 定义接口执行函数
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _DOWNLOADREPORT_CONTROLLER_H_