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
#ifndef _PRINTREPORT_H_
#define _PRINTREPORT_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ������ӡȷ��
* �����ˣ����
 */
class printReportQuery : public PageQuery
{
	DTO_INIT(printReportQuery, PageQuery);
	// �Ƿ��ӡ
	DTO_FIELD(Boolean, printState);
	DTO_FIELD_INFO(printState) {
		info->description = ZH_WORDS_GETTER("print.field.printState");
	}
	// ��ӡ������
	DTO_FIELD(String, reportNum);
	DTO_FIELD_INFO(reportNum) {
		info->description = ZH_WORDS_GETTER("preview.field.reportNum");
	}
	// Ŀ���ӡ��
	DTO_FIELD(String, targetPrinter);
	DTO_FIELD_INFO(targetPrinter) {
		info->description = ZH_WORDS_GETTER("print.field.targetPrinter");
	}
	// ҳ��
	DTO_FIELD(String, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("print.field.page");
	}
	// ÿ���������ҳ��
	DTO_FIELD(String, pageNumPerTable);
	DTO_FIELD_INFO(pageNumPerTable) {
		info->description = ZH_WORDS_GETTER("print.field.pageNumPerTable");
	}
	// �Ƿ��ӡ��������
	DTO_FIELD(Boolean, printSampleCode);
	DTO_FIELD_INFO(printSampleCode) {
		info->description = ZH_WORDS_GETTER("print.field.printSampleCode");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRINTREPORT_H_