#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _OBTAIN_SAMPLE_DETAILS_VO_
#define _OBTAIN_SAMPLE_DETAILS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/ObtainSampleDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ObtainSampleDetailsJsonVO : public JsonVO<ObtainSampleDetailsDTO::Wrapper> {
	DTO_INIT(ObtainSampleDetailsJsonVO, JsonVO<ObtainSampleDetailsDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ObtainSampleDetailsPageJsonVO : public JsonVO<ObtainSampleDetailsPageDTO::Wrapper> {
	DTO_INIT(ObtainSampleDetailsPageJsonVO, JsonVO<ObtainSampleDetailsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_