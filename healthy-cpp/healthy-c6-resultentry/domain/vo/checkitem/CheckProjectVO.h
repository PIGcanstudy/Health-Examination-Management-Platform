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
#ifndef _CHECKPROJECTVO_H_
#define _CHECKPROJECTVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/checkitem/CheckProjectListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/*
*��λ�б���ʾJsonVOʵ��
*/
class CheckProjectJsonVO : public JsonVO<CheckProjectListDTO::Wrapper> {
	DTO_INIT(CheckProjectJsonVO, JsonVO<CheckProjectListDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECKPROJECTVO_H_
