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
#ifndef _PRINTREPORTDTO_H_
#define _PRINTREPORTDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class printReportDTO : public oatpp::DTO
{
	DTO_INIT(printReportDTO, DTO);
	// 打印报告编号
	DTO_FIELD(String, reportNum);
	DTO_FIELD_INFO(reportNum) {
		info->description = ZH_WORDS_GETTER("preview.field.reportNum");
	}
	// 目标打印机
	DTO_FIELD(String, targetPrinter);
	DTO_FIELD_INFO(targetPrinter) {
		info->description = ZH_WORDS_GETTER("print.field.targetPrinter");
	}
	// 页面
	DTO_FIELD(String, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("print.field.page");
	}
	// 每个工作表的页数
	DTO_FIELD(String, pageNumPerTable);
	DTO_FIELD_INFO(pageNumPerTable) {
		info->description = ZH_WORDS_GETTER("print.field.pageNumPerTable");
	}
public:
	printReportDTO() {};
};

class printReportPageDTO : public PageDTO<printReportDTO::Wrapper>
{
	DTO_INIT(printReportPageDTO, PageDTO<printReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRINTREPORTDTO_H_