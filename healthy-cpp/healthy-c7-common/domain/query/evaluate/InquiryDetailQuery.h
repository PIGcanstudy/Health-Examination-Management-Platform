#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenya~
 @Date: 2024/1/18

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
#ifndef _DETAILQUERY_H_
#define _DETAILQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ������ϸ��ҳ��ѯ
 */
class InquiryDetailQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(InquiryDetailQuery, PageQuery);
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("inquiry.field.name"));
	// ����� 
	API_DTO_FIELD_DEFAULT(String, checkId, ZH_WORDS_GETTER("inquiry.field.checkId"));
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, unitName, ZH_WORDS_GETTER("inquiry.field.unitName"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_