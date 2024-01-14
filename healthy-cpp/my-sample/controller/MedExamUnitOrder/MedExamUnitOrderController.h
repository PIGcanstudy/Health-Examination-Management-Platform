/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/01/14 16:12:18

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
#ifndef _MEDEXAMUNITORDER_H_
#define _MEDEXAMUNITORDER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/MedExamUnitOrderQuery.h"
#include "domain/vo/MedExamUintOrderVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MedExamUnitOrderController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(MedExamUnitOrderController)
public: // 定义接口

	ENDPOINT_INFO(queryMedExamUnitOrder) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("MedExamUnitOrder.get.summary"));
		API_DEF_ADD_RSP_JSON_WRAPPER(MedExamUnitOrderJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "unitName", ZH_WORDS_GETTER("MedExamUnitOrder.field.unit-name"), "xxx", false);
	}

	ENDPOINT(API_M_GET, "/MedExamUnitOrder", queryMedExamUnitOrder, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, MedExamUnitOrderQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryMedExamUnitOrder(query));
	}
private: // 定义接口执行函数
	MedExamUnitOrderJsonVO::Wrapper execQueryMedExamUnitOrder(const MedExamUnitOrderQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MEDEXAMUNITORDER_H_