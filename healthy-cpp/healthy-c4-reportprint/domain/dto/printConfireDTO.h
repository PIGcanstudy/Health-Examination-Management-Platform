#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 10:59:38

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
#ifndef _printConfireDTO_H_
#define _printConfireDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ������ӡȷ��
* �����ˣ����
 */
class printConfireDTO : public oatpp::DTO
{
	DTO_INIT(printConfireDTO, DTO);
	// ��ӡ������
	DTO_FIELD(UInt64, reportId);
	DTO_FIELD_INFO(reportId) {
		info->description = ZH_WORDS_GETTER("confire.field.reportId");
	}
	// ��ӡ��������
	DTO_FIELD(String, reportName);
	DTO_FIELD_INFO(reportName) {
		info->description = ZH_WORDS_GETTER("confire.field.reportName");
	}
	// �Ƿ��ӡ
	DTO_FIELD(Boolean, isPrint);
	DTO_FIELD_INFO(isPrint) {
		info->description = ZH_WORDS_GETTER("confire.field.isPrint");
	}
	// ��ӡ���״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("confire.field.status");
	}
};

/*
* ������ӡȷ��
* �����ˣ����
 */
class printConfirePageDTO : public PageDTO<printConfireDTO::Wrapper>
{
	DTO_INIT(printConfirePageDTO, PageDTO<printConfireDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_printConfireDTO_H_