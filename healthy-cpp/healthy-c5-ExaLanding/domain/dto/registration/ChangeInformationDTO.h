#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _CHANGEINFORMATIONDTO_H_
#define _CHANGEINFORMATIONDTO_H_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Ǽǣ�����޸���Ϣ����Ҫ�������Ϣ
 */
class ChangeInformationDTO : public oatpp::DTO
{
	DTO_INIT(ChangeInformationDTO, DTO);
	// t_group_person
	// ���
	// ��Ա����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("registration.changeInformation.personName"));
	// �Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("registration.changeInformation.sex"));
	// ����
	API_DTO_FIELD_DEFAULT(Int32, age, ZH_WORDS_GETTER("registration.changeInformation.age"));
	// ���״��
	API_DTO_FIELD_DEFAULT(String, isMarry, ZH_WORDS_GETTER("registration.changeInformation.isMarry"));
	// ֤������
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("registration.changeInformation.idCard"));
	// �������ڡ�datetime , ��ʲô���͡�
	API_DTO_FIELD_DEFAULT(String, birth, ZH_WORDS_GETTER("registration.changeInformation.birth"));
	// ���顾������Ӳ�ѯ��
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("registration.changeInformation.groupId"));
	
	// �Ǳ��
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("registration.changeInformation.workName"));
	// �ֻ�����
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("registration.changeInformation.mobile"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_CHANGEINFORMATIONDTO_H_