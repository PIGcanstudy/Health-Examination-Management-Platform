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
#ifndef _printConfire_CONTROLLER_H_
#define _printConfire_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printConfireQuery.h"
#include "domain/dto/printConfireDTO.h"
#include "domain/vo/printConfireVO.h"

// 
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * 批量下载PDF报告，报告的选择部分
 * 负责人：晚风
 */
class printConfireController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(printConfireController);

	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryprintConfire) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("confire.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(printConfireJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 定义其他查询参数描述
		// 打印报告编号
		API_DEF_ADD_QUERY_PARAMS(UInt64, "reportId", ZH_WORDS_GETTER("confire.field.reportId"), 12345678, true);
		// 打印报告名称
		API_DEF_ADD_QUERY_PARAMS(String, "reportName", ZH_WORDS_GETTER("confire.field.reportName"), "01 Star Cheak Reoprt", false);
		// 是否打印
		API_DEF_ADD_QUERY_PARAMS(Boolean, "isPrint", ZH_WORDS_GETTER("printSetting.field.isPrint"), true, true);
		// 打印完成状态
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("printSetting.field.status"), "finished", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/confire", queryprintConfire, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, printConfireQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryprintConfire(uq));
	}

private:
	
	printConfirePageJsonVO::Wrapper execQueryprintConfire(const printConfireQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _printConfire_CONTROLLER_H_