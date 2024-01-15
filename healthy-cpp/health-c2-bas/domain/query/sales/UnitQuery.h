#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/13 19:06:21

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
#ifndef _UNITQUERY_H_
#define _UNITQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��λ��ҳ��ѯʵ��
 */
class UnitQuery : public PageQuery
{
	DTO_INIT(UnitQuery, DTO);
	// ��ѯ����
	API_DTO_FIELD_DEFAULT(UInt32, type,  ZH_WORDS_GETTER("unit.field.type"));
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	// ���ô���
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	// ��ϵ��
	API_DTO_FIELD_DEFAULT(String, linkMan, ZH_WORDS_GETTER("unit.field.linkMan"));
	// ��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, linkPhone, ZH_WORDS_GETTER("unit.field.linkPhone"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_