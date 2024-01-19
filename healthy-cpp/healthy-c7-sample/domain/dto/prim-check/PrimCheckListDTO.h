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
#ifndef _PRIMCHECKLISTDTO_H_
#define _PRIMCHECKLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  ��ȡ�����Ŀ�����б���ҳ��
 *  �����ˣ�smartPiggy
 */
class PrimCheckListDTO : public oatpp::DTO
{
	DTO_INIT(PrimCheckListDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("primCheck.field.id"));
	//����
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("primCheck.field.officeName"));
	//�����Ŀ
	API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("primCheck.field.groupItemName"));
	//���С��
	API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("primCheck.field.diagnoseSum"));
};

class PrimCheckListPageDTO : public PageDTO<PrimCheckListDTO::Wrapper>
{
	DTO_INIT(PrimCheckListPageDTO, PageDTO<PrimCheckListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRIMCHECKLISTDTO_H_
