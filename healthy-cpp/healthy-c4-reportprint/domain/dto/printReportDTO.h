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
	// 报告id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("preview.field.reportNum");
	}
	// 报告打印次数
	DTO_FIELD(UInt32, reportPrintingNum);
	DTO_FIELD_INFO(reportPrintingNum) {
		info->description = ZH_WORDS_GETTER("addition.field.printNum");
	}
	// 打印状态
	DTO_FIELD(String, printState);
	DTO_FIELD_INFO(printState) {
		info->description = ZH_WORDS_GETTER("print.field.printState");
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