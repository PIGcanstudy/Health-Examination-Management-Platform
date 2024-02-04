#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _UPDATEINFORMATIONDO_H_
#define _UPDATEINFORMATIONDO_H_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UpdateInformationDO
{
	// ��Ա����
	CC_SYNTHESIZE(string, personName, PersonName);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(uint64_t, age, Age);
	// ���״��
	CC_SYNTHESIZE(string, isMarry, IsMarry);
	// ֤������
	CC_SYNTHESIZE(string, idCard, IdCard);
	// ��������
	CC_SYNTHESIZE(string, birth, Birth);
	// ����
	CC_SYNTHESIZE(string, groupId, GroupId);
	// ��λ����
	CC_SYNTHESIZE(string, workName, WorkName);
	// �ֻ�����
	CC_SYNTHESIZE(string, mobile, Mobile);


public:
	UpdateInformationDO() {
		personName = "";
		sex = "";
		age = -1;
		isMarry = "";
		idCard = "";
		birth = "";
		groupId = "";
		workName = "";
		mobile = "";
	}
};

#endif // !_UPDATEINFORMATIONDO_H_
