#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/1/27 

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
#ifndef _INQUIRYDETAIL_DO_
#define _INQUIRYDETAIL_DO_
#include "../DoInclude.h"

/**
 * ������ϸ���ݿ�ʵ����
 */
class InquiryDetailDO
{
	CC_SYNTHESIZE(string, id, Id);
	// �������
	CC_SYNTHESIZE(string, workYear, WorkYear);
	// �����¶�
	CC_SYNTHESIZE(string, workMonth, WorkMonth);
	// ���״��
	CC_SYNTHESIZE(string, isMarry, IsMarry);
	//��������
	CC_SYNTHESIZE(string, exposureWorkYear, ExposureWorkYear);
	//��������
	CC_SYNTHESIZE(string, exposureWorkMonth, ExposureWorkMonth);

	//�Ǳ���
	
	//�Ļ��̶�
	CC_SYNTHESIZE(string, education, Education);
	//��ͥ��ַ
	CC_SYNTHESIZE(string, familyAddress, FamilyAddress);
	//��������
	CC_SYNTHESIZE(string, workTypeText, WorkTypeText);
	//������������
	CC_SYNTHESIZE(string, workName, WorkName);
	//��������
	CC_SYNTHESIZE(string, department, Department);



public:
	InquiryDetailDO() {
		id = "";
		workYear = "";
		workMonth = "";
		isMarry = "";
		exposureWorkYear = "";
		exposureWorkMonth = "";

		//�Ǳ��룬����Ϊ��
		education = "";
		familyAddress = "";
		workTypeText = "";
		workName = "";
		department = "";
	}
};

#endif // !_INQUIRYDETAIL_DO_

