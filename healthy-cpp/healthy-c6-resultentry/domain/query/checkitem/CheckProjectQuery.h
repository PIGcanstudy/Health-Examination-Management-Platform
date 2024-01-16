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
#ifndef _CHECKPROJECT_H_
#define _CHECKPROJECT_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*定义一个查询体检套餐内具体单项的传输模型
*/

class CheckProjectQuery : public oatpp::DTO
{
	DTO_INIT(CheckProjectQuery, DTO);
	//所选的套餐项目名称
	API_DTO_FIELD_DEFAULT(String, combo_name, ZH_WORDS_GETTER("checkitem.combo.name"));
	//所选的在已选套餐项目以外的选检项目名称
	API_DTO_FIELD_DEFAULT(String, comboitem_name, ZH_WORDS_GETTER("checkitem.comboitem.name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECKPROJECT_H_
