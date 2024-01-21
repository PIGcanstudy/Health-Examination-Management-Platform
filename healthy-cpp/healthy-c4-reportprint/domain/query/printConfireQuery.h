#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 11:36:29

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
#ifndef _printConfire_H_
#define _printConfire_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 批量下载PDF报告
* 负责人：晚风
 */
class printConfireQuery : public PageQuery
{
	DTO_INIT(printConfireQuery, PageQuery);
	// 
	API_DTO_FIELD_DEFAULT(UInt64, reportNum, ZH_WORDS_GETTER("confirm.field.reportNum"));
	// 
	API_DTO_FIELD_DEFAULT(String, reportName, ZH_WORDS_GETTER("confirm.field.reportName"));
	// 
	API_DTO_FIELD_DEFAULT(Boolean, status, ZH_WORDS_GETTER("confirm.field.status"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_printConfire_H_