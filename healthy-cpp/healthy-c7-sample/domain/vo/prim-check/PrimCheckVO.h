#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-18

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
#ifndef _PRIMCHECKVO_H_
#define _PRIMCHECKVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/prim-check/PrimCheckListDTO.h"
#include"../../dto/prim-check/PrimCheckDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 项目结论列表JsonVO
*/
class PrimCheckListJsonVO : public JsonVO<PrimCheckListDTO::Wrapper>
{
	DTO_INIT(PrimCheckListJsonVO, JsonVO<PrimCheckListDTO::Wrapper>);
};
class PrimCheckListPageJsonVO : public JsonVO<PrimCheckListPageDTO::Wrapper>
{
	DTO_INIT(PrimCheckListPageJsonVO, JsonVO<PrimCheckListPageDTO::Wrapper>);
};

/*
* 项目结论详情JsonVO
*/
class PrimCheckDetailJsonVO : public JsonVO<PrimCheckDetailDTO::Wrapper>
{
	DTO_INIT(PrimCheckDetailJsonVO, JsonVO<PrimCheckDetailDTO::Wrapper>);
};
class PrimCheckDetailPageJsonVO : public JsonVO<PrimCheckDetailPageDTO::Wrapper>
{
	DTO_INIT(PrimCheckDetailPageJsonVO, JsonVO<PrimCheckDetailPageDTO::Wrapper>)
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_PRIMCHECKVO_H_