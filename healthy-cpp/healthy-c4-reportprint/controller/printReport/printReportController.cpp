/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 13:00:32

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
#include "stdafx.h"
#include <iostream>
#include "printReportController.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

/*
 * 打印PDF报告
 */
printReportPageJsonVO::Wrapper printReportController::execQueryprintReport(const printReportQuery::Wrapper& query)
{

	printReportPageJsonVO::Wrapper vo = printReportPageJsonVO::createShared();
	auto dto = printReportPageDTO::createShared();
	if (query->pageIndex == 1)
	{
		vo->success(dto);
	}
	else
	{
		vo->fail(dto);
	}
	return vo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> printReportController::execDownloadSampleCode(const String& sampleCodeNum)
{
	// 构建样本条码全路径
	std::string code_fullPath = "public/static/sampleCode/sampleCode.jpg";

	// 读取样本条码
	auto code_fstring = String::loadFromFile(code_fullPath.c_str());

	// 判断是否读取成功
	if (!code_fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto code_response = createResponse(Status::CODE_200, code_fstring);

	// 设置响应头信息
	code_response->putHeader("Content-Disposition", "attachment; filename=" + sampleCodeNum.getValue("") + ".jpg");

	// 影响成功结果
	return code_response;
}