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
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("select.field.name");
	}
	// 体检人员编号
	DTO_FIELD(UInt64, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("select.field.personId");
	}
	// 报告编号
	DTO_FIELD(UInt64, reportId);
	DTO_FIELD_INFO(reportId) {
		info->description = ZH_WORDS_GETTER("select.field.reportId");
	}
	// 报告名称
	DTO_FIELD(String, reportName);
	DTO_FIELD_INFO(reportName) {
		info->description = ZH_WORDS_GETTER("select.field.reportName");
	}
	// 工作单位名称
	DTO_FIELD(String, dept);
	DTO_FIELD_INFO(dept) {
		info->description = ZH_WORDS_GETTER("select.field.dept");
	}
	// 体检日期
	DTO_FIELD(String, checkDate);
	DTO_FIELD_INFO(checkDate) {
		info->description = ZH_WORDS_GETTER("select.field.checkDate");
	}
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