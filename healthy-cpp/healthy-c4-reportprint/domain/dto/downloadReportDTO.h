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
#ifndef _DOWNLOADREPORTDTO_H_
#define _DOWNLOADREPORTDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 下载设置
* 负责人：晚风
 */
class downloadReportDTO : public oatpp::DTO
{
	DTO_INIT(downloadReportDTO, DTO);
	// 下载报告编号
	DTO_FIELD(String, reportNum);
	DTO_FIELD_INFO(reportNum) {
		info->description = ZH_WORDS_GETTER("preview.field.reportNum");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_DOWNLOADREPORTDTO_H_