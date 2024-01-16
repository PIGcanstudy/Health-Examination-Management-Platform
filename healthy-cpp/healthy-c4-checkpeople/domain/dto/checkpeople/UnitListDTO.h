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
#ifndef _UNITLISTDTO_H_
#define _UNITLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	��λ�б������ݶ���ʵ�塪������ҳ������ʵ��
*/
class UnitListDTO : public oatpp::DTO
{
	
	//�����ֶ�
	DTO_INIT(UnitListDTO, DTO);
	//Ψһ���
	/*���� person_name�Ա� sex֤������  id_card�������� birth���� age�Ƿ��� is_marry�ֻ����� mobile*/
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unit.field.personName"));
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unit.field.sex"));
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(String, birth, ZH_WORDS_GETTER("unit.field.birth"));
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unit.field.age"));
	API_DTO_FIELD_DEFAULT(String, isMarry, ZH_WORDS_GETTER("unit.field.isMarry"));
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unit.field.mobile"));
};

/*
	��λ��ҳ�б������ݶ���ʵ�塪����ҳ������ʵ��
*/
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper>
{
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNITLISTDTO_H_