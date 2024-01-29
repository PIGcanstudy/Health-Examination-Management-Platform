#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 13:05:04

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
#ifndef _PRINTREPORT_CONTROLLER_H_
#define _PRINTREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printReportQuery.h"
#include "domain/dto/printReportDTO.h"
#include "domain/vo/printReportVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * 打印PDF报告
 */
class printReportController : public oatpp::web::server::api::ApiController // 1 
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(printReportController);

	// 定义接口
public:
	// 定义一个报告打印确认接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("print.get.print"), modifyprintReport, Uint64JsonVO::Wrapper);
	// 定义接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/printConfire", modifyprintReport, BODY_DTO(printReportDTO::Wrapper, dto), execModifyprintReport(dto));


	// 定义一个样本条码获取接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		// 接口标题
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("print.get.sampleCode"), Void);
		// 条码编号
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeNum", ZH_WORDS_GETTER("addition.field.sampleCodeNum"), "436591946372", false);
		// 条码名称
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeName", ZH_WORDS_GETTER("addition.field.sampleCodeName"), ZH_WORDS_GETTER("addition.test.sampleCodeName"), false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/downloadSampleCode", downloadFile, QUERY(String, sampleCodeName)) {
		return execDownloadSampleCode(sampleCodeName);
	}

private:
	// 报告打印 
	StringJsonVO::Wrapper execModifyprintReport(const printReportDTO::Wrapper& dto);
	// 获取样本条码
	std::shared_ptr<OutgoingResponse> execDownloadSampleCode(const String& sampleCodeName);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTREPORT_CONTROLLER_H_