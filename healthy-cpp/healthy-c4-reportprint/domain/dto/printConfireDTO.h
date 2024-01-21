#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 10:59:38

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
#ifndef _printConfireDTO_H_
#define _printConfireDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 批量下载PDF报告
* 负责人：晚风
 */
class printConfireDTO : public oatpp::DTO
{
	DTO_INIT(printConfireDTO, DTO);
	// 
	API_DTO_FIELD_DEFAULT(UInt64, reportNum, ZH_WORDS_GETTER("confire.field.reportNum"));
	// 
	API_DTO_FIELD_DEFAULT(String, reportName, ZH_WORDS_GETTER("confire.field.reportName"));
	// 
	API_DTO_FIELD_DEFAULT(Boolean, status, ZH_WORDS_GETTER("confire.field.status"));

};

/**
 *
 */
class printConfirePageDTO : public PageDTO<printConfireDTO::Wrapper>
{
	DTO_INIT(printConfirePageDTO, PageDTO<printConfireDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_printConfireDTO_H_