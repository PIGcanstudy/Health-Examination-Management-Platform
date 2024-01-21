#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 11:34:14

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
#ifndef _downloadSetting_VO_
#define _downloadSetting_VO_

#include "../GlobalInclude.h"
#include "../dto/downloadSettingDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 批量下载PDF报告
* 负责人：晚风
 */
class downloadSettingJsonVO : public JsonVO<downloadSettingDTO::Wrapper> {
	DTO_INIT(downloadSettingJsonVO, JsonVO<downloadSettingDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_downloadSetting_VO_