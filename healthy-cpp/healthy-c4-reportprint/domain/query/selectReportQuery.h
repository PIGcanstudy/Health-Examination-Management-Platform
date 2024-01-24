#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 11:36:29

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
#ifndef _selectREPORT_H_
#define _selectREPORT_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������PDF����
 * �����ˣ�����
 */
class selectReportQuery : public PageQuery
{
	DTO_INIT(selectReportQuery, PageQuery);
	// ��ѯ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("select.field.type"));
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("select.field.name"));
	// �������
	API_DTO_FIELD_DEFAULT(String, downloadpath, ZH_WORDS_GETTER("select.field.downloadpath"));
	// �����
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("select.field.testNum"));
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("select.field.dept"));
	// �������
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("select.field.checkDate"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_selectREPORT_H_