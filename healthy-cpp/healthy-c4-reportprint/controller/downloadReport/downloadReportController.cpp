/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:37:57

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
#include "downloadReportController.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> downloadReportController::execDownloadFile(const String& reportName)
{
	// 构建PDF报告全路径
	std::string report_fullPath = "public/static/report/sample.pdf" ;

	// 读取PDF报告
	auto report_fstring = String::loadFromFile(report_fullPath.c_str());

	// 判断是否读取成功
	if (!report_fstring)
	{
		std::cerr << "Failed to open report: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Report Not Found");
	}

	// 创建响应头
	auto report_response = createResponse(Status::CODE_200, report_fstring);

	// 设置响应头信息
	report_response->putHeader("Content-Disposition", "attachment; filename=" + reportName.getValue("") + ".pdf") ;

	// 影响成功结果
	return report_response;
}
