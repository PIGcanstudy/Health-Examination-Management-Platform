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
#ifndef _downloadSettingDTO_H_
#define _downloadSettingDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 批量下载PDF报告
* 负责人：晚风
 */
class downloadSettingDTO : public oatpp::DTO
{
	DTO_INIT(downloadSettingDTO, DTO);
	//
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("downloadSetting.field.id"));
	// 
	API_DTO_FIELD_DEFAULT(String, reportNum, ZH_WORDS_GETTER("downloadSetting.field.reportNum"));
	// 
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("downloadSetting.field.href"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_downloadSettingDTO_H_