#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ��λ��ҳ��ѯʵ��
*/

class UnitQuery : public PageQuery
{
	DTO_INIT(UnitQuery, DTO);
	//��ѯ����
	//API_DTO_FIELD_DEFAULT(UInt32,type, ZH_WORDS_GETTER("evalue.field.type"));
	//�������
	API_DTO_FIELD_DEFAULT(UInt32,ispass, ZH_WORDS_GETTER("evalue.field.ispass"));
	// ����״̬  ������Ա�ڸ�����Ա��Ϣ���в�ѯ
	API_DTO_FIELD_DEFAULT(UInt32, isRecheck, ZH_WORDS_GETTER("evalue.field.isRecheck"));
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("evalue.field.startDate"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("evalue.field.endDate"));
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("evalue.field.personName"));
	//�����
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("evalue.field.testNum"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String,dept, ZH_WORDS_GETTER("evalue.field.dept"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_