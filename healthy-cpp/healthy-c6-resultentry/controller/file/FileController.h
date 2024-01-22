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
#ifndef _FILECONTROLLER_H_
#define _FILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class FileController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FileController);
public:
	// 定义一个单文件上传接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/file/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));


private: // 定义接口执行函数
	// 执行单文件上传处理
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
	
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_