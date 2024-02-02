#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#ifndef _RESULTSLIST_QUERY_
#define _RESULTSLIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取体检结果分页查询对象
 */
class ResultsListQuery : public PageQuery
{
	DTO_INIT(ResultsListQuery, PageQuery);
	// 查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("results.field.type"));
	// ID
	API_DTO_FIELD_DEFAULT(UInt32, id, ZH_WORDS_GETTER("results.field.id"));
	// 姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("results.field.name"));
	// 体检编号 
	API_DTO_FIELD_DEFAULT(String, checkId, ZH_WORDS_GETTER("results.field.checkId"));
	// 检查种类
	API_DTO_FIELD_DEFAULT(String, checkType, ZH_WORDS_GETTER("results.field.checkType"));
	//身份证号
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("results.field.idCard"));
	//危害因素
	API_DTO_FIELD_DEFAULT(String, dangerFactors, ZH_WORDS_GETTER("results.field.dangerFactors"));
	//状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("results.field.state"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("results.field.sex"));
	//体检日期
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("results.field.checkDate"));
	//体检结论
	API_DTO_FIELD_DEFAULT(String, checkResults, ZH_WORDS_GETTER("results.field.checkResults"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTSLIST_QUERY_