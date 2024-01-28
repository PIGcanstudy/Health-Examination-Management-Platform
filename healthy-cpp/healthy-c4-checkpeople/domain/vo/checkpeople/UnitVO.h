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
#ifndef _UNITVO_H_
#define _UNITVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/checkpeople/UnitListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
单位列表显示JsonVO实体,用于响应给客户端的Json对象
*/
class UnitListJsonVO : public JsonVO<UnitListDTO::Wrapper>       //包装类型是dto层的UnitListDTO
{
	DTO_INIT(UnitListJsonVO, JsonVO<UnitListDTO::Wrapper>);
};

/*
单位列表显示分页jsonvo
*/
class UnitListPageJsonVO : public JsonVO<UnitListPageDTO::Wrapper>
{
	DTO_INIT(UnitListPageJsonVO, JsonVO<UnitListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNITVO_H_