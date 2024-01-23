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
#ifndef _PRINTCONFIRM_CONTROLLER_H_
#define _PRINTCONFIRM_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printConfirmQuery.h"
#include "domain/dto/printConfirmDTO.h"
#include "domain/vo/printConfirmVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * 批量下载PDF报告，报告的选择部分
 * 负责人：晚风
 */
class printConfirmController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(printConfirmController);

	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryprintConfirm) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("confirm.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(printConfirmJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 定义其他查询参数描述
		// 打印报告编号
		API_DEF_ADD_QUERY_PARAMS(UInt64, "printReportId", ZH_WORDS_GETTER("confirm.field.printReportId"), 12345678, true);
		// 打印报告名称
		API_DEF_ADD_QUERY_PARAMS(String, "printReportName", ZH_WORDS_GETTER("confirm.field.printReportName"), "01 Star Cheak Reoprt", false);
		// 是否打印
		API_DEF_ADD_QUERY_PARAMS(Boolean, "isPrint", ZH_WORDS_GETTER("confirm.field.isPrint"), true, true);
		// 打印完成状态
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("confirm.field.status"), "finished", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/confirm", queryprintConfirm, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, printConfirmQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryprintConfirm(uq));
	}

private:
	
	printConfirmPageJsonVO::Wrapper execQueryprintConfirm(const printConfirmQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTCONFIRM_CONTROLLER_H_