#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _COMBOITEMVO_H_
#define _COMBOITEMVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/checkitem/ComboItemDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/*
*单位列表显示JsonVO实体
*/
class ComboItemJsonVO : public JsonVO<ComboItemDTO::Wrapper> {
	DTO_INIT(ComboItemJsonVO, JsonVO<ComboItemDTO::Wrapper>);

};
/**
*单位列表显示分页JsonVO实体
*/

class ComboItemPageJsonVO : public JsonVO<ComboItemPageDTO::Wrapper> {
	DTO_INIT(ComboItemJsonVO, JsonVO<ComboItemDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMBOITEMVO_H_
