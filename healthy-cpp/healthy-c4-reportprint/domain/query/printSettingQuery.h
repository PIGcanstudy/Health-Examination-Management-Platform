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
#ifndef _PRINTSETTING_H_
#define _PRINTSETTING_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��������PDF����
* �����ˣ����
 */
class printSettingQuery : public PageQuery
{
	DTO_INIT(printSettingQuery, PageQuery);
	// ��ӡ��ֽ�ߴ�
	DTO_FIELD(String, papersize);
	DTO_FIELD_INFO(papersize) {
		info->description = ZH_WORDS_GETTER("printSetting.field.papersize");
	}
	// ��ӡҳ�淶Χ
	DTO_FIELD(String, pagerange);
	DTO_FIELD_INFO(pagerange) {
		info->description = ZH_WORDS_GETTER("printSetting.field.pagerange");
	}
	// �Ƿ�˫��
	DTO_FIELD(Boolean, isDoubleSid);
	DTO_FIELD_INFO(isDoubleSid) {
		info->description = ZH_WORDS_GETTER("printSetting.field.isDoubleSid");
	}
	// ��ӡ����
	DTO_FIELD(UInt32, copiesNum);
	DTO_FIELD_INFO(copiesNum) {
		info->description = ZH_WORDS_GETTER("printSetting.field.copiesNum");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRINTSETTING_H_
