/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/01/14 18:40:43

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
#ifndef _UNITREPORT_H_
#define _UNITREPORT_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include "domain/vo/UnitReportJsonVO.h"
#include "domain/dto/UnitReportDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UnitReportController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(UnitReportController)
public: // 定义接口
	ENDPOINT_INFO(queryUnitReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("UnitReport.get.summary"));
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitReportJsonVO);
	}

	// 定义接口处理
	ENDPOINT(API_M_GET, "/UnitReport", queryUnitReport) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnitReport());
	}
private: // 定义接口执行函数
	UnitReportJsonVO::Wrapper execQueryUnitReport();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_UNITREPORT_H_