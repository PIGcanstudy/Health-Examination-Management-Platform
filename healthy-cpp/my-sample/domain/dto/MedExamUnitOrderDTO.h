/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/01/15 0:26:33

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
#ifndef _MEDEXAMUNITORDERDTO_H_
#define _MEDEXAMUNITORDERDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MedExamUnitOrderDTO : public oatpp::DTO
{
	DTO_INIT(MedExamUnitOrderDTO, DTO)
	DTO_FIELD(String, unitName);
	DTO_FIELD_INFO(unitName) {
		info->description = ZH_WORDS_GETTER("MedExamUnitOrder.field.unit-name");
	}
public:
	MedExamUnitOrderDTO() {
		unitName = "1";
	}
};

class MedExamUnitOrderListDTO : public oatpp::DTO
{
	DTO_INIT(MedExamUnitOrderListDTO, DTO)
	// 数据列表
	API_DTO_FIELD(List<MedExamUnitOrderDTO::Wrapper>, itemList, "list", false, {});
public:
	void push(MedExamUnitOrderDTO::Wrapper item) {
		this->itemList->push_back(item);
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEDEXAMUNITORDERDTO_H_