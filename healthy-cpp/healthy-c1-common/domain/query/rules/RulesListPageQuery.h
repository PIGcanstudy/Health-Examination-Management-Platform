
/*
 Copyright Zero One Star. All rights reserved.

 @Author: c1-pepper
 @Date: 2024/1/14 

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
#ifndef _RULESLISTPAGEQUERY_H_
#define _RULESLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取指定项目规则列表(分页)
 */
class RulesListPageQuery : public PageQuery
{
	//?pageNumber=1&pageSize=10&sort=create_time&order=desc
	// 定义初始化
	DTO_INIT(RulesListPageQuery, PageQuery);

    // ID
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("rules.field.id"));
	//// current
	//API_DTO_FIELD_DEFAULT(String, current, ZH_WORDS_GETTER("rules.field.current"));
	//// hitCount
	//API_DTO_FIELD_DEFAULT(Int32, hitCount, ZH_WORDS_GETTER("rules.field.hitCount"));
	//// maxLimit
	//API_DTO_FIELD_DEFAULT(Int32, maxLimit, ZH_WORDS_GETTER("rules.field.maxList"));
	//// optimizeCountSql
	//API_DTO_FIELD_DEFAULT(String, optimizeCountSql, ZH_WORDS_GETTER("rules.field.optimizeCountSql"));
	//// orders
	//API_DTO_FIELD_DEFAULT(String, orders, ZH_WORDS_GETTER("rules.field.orders"));
	//// pages
	//API_DTO_FIELD_DEFAULT(Int32, pages, ZH_WORDS_GETTER("rules.field.pages"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RULESLIST_H_