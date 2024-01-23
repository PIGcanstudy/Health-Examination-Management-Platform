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
#ifndef _SELECTREPORT_CONTROLLER_H_
#define _SELECTREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/selectReportQuery.h"
#include "domain/dto/selectReportDTO.h"
#include "domain/vo/selectReportVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * 选择要下载的报告
 * 负责人：晚风
 */
class selectReportController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(selectReportController);

	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryselectReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("select.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(selectReportJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 定义其他查询参数描述
		// 姓名
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("select.field.name"), "Li Ming", false);
		// 体检人员编号
		API_DEF_ADD_QUERY_PARAMS(UInt64, "personId", ZH_WORDS_GETTER("select.field.personId"), 123456, false);
		// 报告编号
		API_DEF_ADD_QUERY_PARAMS(UInt64, "printReportId", ZH_WORDS_GETTER("select.field.printReportId"), 12345678, true);
		// 报告名称
		API_DEF_ADD_QUERY_PARAMS(String, "reportName", ZH_WORDS_GETTER("select.field.reportName"), "01 Star Cheak Reoprt", false);
		// 工作单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("select.field.dept"), "01Star", false);
		// 体检日期
		API_DEF_ADD_QUERY_PARAMS(String, "checkDate", ZH_WORDS_GETTER("select.field.checkDate"), "20231209", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/select", queryselectReport, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, selectReportQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryselectReport(uq));
	}

private:
	
	selectReportPageJsonVO::Wrapper execQueryselectReport(const selectReportQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SELECTREPORT_CONTROLLER_H_