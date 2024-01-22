#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 样本分页查询实体
 */
class SampleQuery : public PageQuery
{
	DTO_INIT(SampleQuery, PageQuery);

	//查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("sample.field.type"));

	//名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sample.field.name"));
	//样本代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("sample.field.code"));
	//关联码
	API_DTO_FIELD_DEFAULT(String, liscode, ZH_WORDS_GETTER("sample.field.liscode"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_