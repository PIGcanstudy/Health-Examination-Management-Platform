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
#ifndef _selectREPORTDTO_H_
#define _selectREPORTDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 批量下载PDF报告
* 负责人：晚风
 */
class selectReportDTO : public oatpp::DTO
{
	DTO_INIT(selectReportDTO, DTO);
	// 
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("select.field.id"));
	// 
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("select.field.name"));
	// 
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("select.field.age"));
	// 
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("select.field.sex"));
	// 
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("select.field.statu"));
	// 
	API_DTO_FIELD_DEFAULT(Boolean, downloadState, ZH_WORDS_GETTER("select.field.downloadState"));

};

/**
 *
 */
class selectReportPageDTO : public PageDTO<selectReportDTO::Wrapper>
{
	DTO_INIT(selectReportPageDTO, PageDTO<selectReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_selectREPORTDTO_H_