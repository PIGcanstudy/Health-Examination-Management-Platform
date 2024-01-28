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
#ifndef _ADD_VO_
#define _ADD_VO_

#include "../../GlobalInclude.h"
#include "../../dto/addpeople/AddDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddJsonVO : public JsonVO<AddDTO::Wrapper> {
	DTO_INIT(AddJsonVO, JsonVO<AddDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddPageJsonVO : public JsonVO<AddPageDTO::Wrapper> {
	DTO_INIT(AddPageJsonVO, JsonVO<AddPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADD_VO_