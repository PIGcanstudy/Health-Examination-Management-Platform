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
 * 负责人：晚风
 */
class printReportController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(printReportController);

	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryprintReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("print.get.view"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(printReportJsonVO);

		// 定义其他查询参数描述
		// 是否打印
		API_DEF_ADD_QUERY_PARAMS(Boolean, "printState", ZH_WORDS_GETTER("print.field.printState"), false, true);
		// 待打印的报告编号
		API_DEF_ADD_QUERY_PARAMS(String, "reportNum", ZH_WORDS_GETTER("preview.field.reportNum"), "1202204010001", true);
		// 目标打印机
		API_DEF_ADD_QUERY_PARAMS(String, "targetPrinter", ZH_WORDS_GETTER("print.field.targetPrinter"), "save as PDF", true);
		// 页面
		API_DEF_ADD_QUERY_PARAMS(String, "page", ZH_WORDS_GETTER("print.field.page"), "all", true);
		// 每个工作表的页数
		API_DEF_ADD_QUERY_PARAMS(UInt16, "pageNumPerTable", ZH_WORDS_GETTER("print.field.pageNumPerTable"), 1, true);
		// 是否打印样本条码
		API_DEF_ADD_QUERY_PARAMS(Boolean, "printSampleCode", ZH_WORDS_GETTER("print.field.printSampleCode"), false, true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/printReport", queryprintReport, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, printReportQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryprintReport(uq));
	}

private:
	
	printReportPageJsonVO::Wrapper execQueryprintReport(const printReportQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTREPORT_CONTROLLER_H_