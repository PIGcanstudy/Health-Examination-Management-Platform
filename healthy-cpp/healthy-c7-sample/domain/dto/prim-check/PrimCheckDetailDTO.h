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
#ifndef _PRIMCHECKDETAILDTO_H_
#define _PRIMCHECKDETAILDTO_H_

#include "../../GlobalInclude.h"
#include"./PrimCheckListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  ��ȡ�����Ŀ�������飨��ҳ��
 *  �����ˣ�smartPiggy
 */
class PrimCheckDetailDTO : public PrimCheckListDTO
{
	DTO_INIT(PrimCheckDetailDTO, PrimCheckListDTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("primCheck.field.id"));
	//������Ŀ��
	API_DTO_FIELD_DEFAULT(String, orderGroupItemProjectName, ZH_WORDS_GETTER("primCheck.field.orderGroupItemProjectName"));
	//���
	API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("primCheck.field.result"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, unitCode, ZH_WORDS_GETTER("primCheck.field.unitCode"));
	//�ο���Χ
	API_DTO_FIELD_DEFAULT(String, scope, ZH_WORDS_GETTER("primCheck.field.scope"));
	//��ʾ
	API_DTO_FIELD_DEFAULT(String, tips, ZH_WORDS_GETTER("primCheck.field.tips"));
	//�쳣
	API_DTO_FIELD_DEFAULT(UInt32, status, ZH_WORDS_GETTER("primCheck.field.status"));
	//Ӱ������
	API_DTO_FIELD_DEFAULT(String, seeing, ZH_WORDS_GETTER("primCheck.field.seeing"));
};

class PrimCheckDetailPageDTO : public PrimCheckListPageDTO
{
	DTO_INIT(PrimCheckDetailPageDTO, PrimCheckListPageDTO);
	
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRIMCHECKDETAILDTO_H_
