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
#ifndef _USERDTO_H_
#define _USERDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  ��ȡ������ϸ��������
 */

class InquiryDetailDTO : public oatpp::DTO
{
	DTO_INIT(InquiryDetailDTO, DTO);
	// �������
	API_DTO_FIELD_DEFAULT(UInt32, workYear, ZH_WORDS_GETTER("inquiry.field.workYear"));
	// �����¶�
	API_DTO_FIELD_DEFAULT(UInt32, workMonth, ZH_WORDS_GETTER("inquiry.field.workMonth"));
	// ���״��
	API_DTO_FIELD_DEFAULT(String, maritalStatus, ZH_WORDS_GETTER("inquiry.field.maritalStatus"));
	//��������
	API_DTO_FIELD_DEFAULT(UInt32, needYear, ZH_WORDS_GETTER("inquiry.field.needYear"));
	//��������
	API_DTO_FIELD_DEFAULT(UInt32, needmonth, ZH_WORDS_GETTER("inquiry.field.needMonth"));

	//�Ǳ���
	
	//�Ļ��̶�
	API_DTO_FIELD_DEFAULT(String, culture, ZH_WORDS_GETTER("inquiry.field.culture"));
	//��ͥ��ַ
	API_DTO_FIELD_DEFAULT(String, homeAddress, ZH_WORDS_GETTER("inquiry.field.homeAddress"));
	//��������
	API_DTO_FIELD_DEFAULT(String, jobName, ZH_WORDS_GETTER("inquiry.field.jobName"));
	//������������
	API_DTO_FIELD_DEFAULT(String, jobOrderName, ZH_WORDS_GETTER("inquiry.field.jobOrderName"));
	//��������
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("inquiry.field.department"));

};

/**
 * ����һ��������ϸ��Ϣ��ҳ�������
 */
class InquiryDetailPageDTO : public PageDTO<InquiryDetailDTO::Wrapper>
{
	DTO_INIT(InquiryDetailPageDTO, PageDTO<InquiryDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_