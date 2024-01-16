#pragma once
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
#ifndef _CHECKPROJECTLISTDTO_H_
#define _CHECKPROJECTLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�������Ŀ�б�����ݴ���ģ��
 */
class CheckProjectListDTO : public oatpp::DTO
{
	DTO_INIT(CheckProjectListDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("checkitem.checkproject.id"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("checkitem.comboitem.name"));
	//ԭ��
	API_DTO_FIELD_DEFAULT(Float64, sale_price, ZH_WORDS_GETTER("checkitem.portfolio_project.sale_price"));
	//�ۿ�
	API_DTO_FIELD_DEFAULT(UInt32, discount, ZH_WORDS_GETTER("checkitem.comboitem.discount"));
	//�ۿۼ�
	API_DTO_FIELD_DEFAULT(Float64, discount_price, ZH_WORDS_GETTER("checkiten.comboitem.discount_price"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, project_type, ZH_WORDS_GETTER("checkitem.comboitem.project_type"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECKPROJECTLISTDTO_H_

