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
#ifndef _PREVIEWREPORTDTO_H_
#define _PREVIEWREPORTDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表数据传输对象实体
 * 负责人：小智
 */
class PreviewReportDTO : public oatpp::DTO
{
	DTO_INIT(PreviewReportDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("print.field.id"));
	// 报告编号
	API_DTO_FIELD_DEFAULT(String, reportNum, ZH_WORDS_GETTER("print.field.reportNum"));
	// PDF地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("print.field.href"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORTDTO_H_