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
#ifndef _DOWNLOADSETTING_CONTROLLER_H_
#define _DOWNLOADSETTING_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/downloadSettingQuery.h"
#include "domain/dto/downloadSettingDTO.h"
#include "domain/vo/downloadSettingVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 批量下载PDF报告，报告的下载设置部分
 * 负责人：晚风
 */
class downloadSettingController : public oatpp::web::server::api::ApiController // 1 
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(downloadSettingController);

	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querydownloadSetting) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("downloadSetting.get.view"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(downloadSettingJsonVO);

		// 定义查询参数描述
		// 待下载报告编号
		API_DEF_ADD_QUERY_PARAMS(UInt64, "downloadReportId", ZH_WORDS_GETTER("downloadSetting.field.downloadRportId"),12345678, true);
		// 下载路径
		API_DEF_ADD_QUERY_PARAMS(String, "downloadpath", ZH_WORDS_GETTER("downloadSetting.field.downloadpath"), "C:/user", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/downloadSetting", querydownloadSetting, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, downloadSettingQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerydownloadSetting(uq));
	}

private:

	downloadSettingJsonVO::Wrapper execQuerydownloadSetting(const downloadSettingQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DOWNLOADSETTIN_CONTROLLER_H_