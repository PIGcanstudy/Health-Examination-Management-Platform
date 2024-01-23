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
#ifndef _PRINTCONFIRM_VO_
#define _PRINTCONFIRM_VO_

#include "../GlobalInclude.h"
#include "../dto/printConfirmDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��������PDF����
* �����ˣ����
 */
class printConfirmJsonVO : public JsonVO<printConfirmDTO::Wrapper> {
	DTO_INIT(printConfirmJsonVO, JsonVO<printConfirmDTO::Wrapper>);
};

/**
* ��������PDF����
* �����ˣ����
 */

class printConfirmPageJsonVO : public JsonVO<printConfirmPageDTO::Wrapper> {
	DTO_INIT(printConfirmPageJsonVO, JsonVO<printConfirmPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRINTCONFIRM_VO_