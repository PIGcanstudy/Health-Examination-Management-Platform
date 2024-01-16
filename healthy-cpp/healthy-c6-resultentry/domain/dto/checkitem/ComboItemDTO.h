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
#ifndef _COMBOITEMDTO_H_
#define _COMBOITEMDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个体检单项的数据列表传输模型
 */
class ComboItemDTO : public oatpp::DTO
{
	DTO_INIT(ComboItemDTO, DTO);
	//唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("checkitem.comboitem.id"));
	//单项名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("checkitem.comboitem.name"));
	//单项销售价
	API_DTO_FIELD_DEFAULT(Float64, sale_price, ZH_WORDS_GETTER("checkitem.portfolio_project.sale_price"));
};

/*
*单位列表分页传输实体
*/

class ComboItemPageDTO : public PageDTO<ComboItemDTO::Wrapper> {

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_COMBOITEMDTO_H_
