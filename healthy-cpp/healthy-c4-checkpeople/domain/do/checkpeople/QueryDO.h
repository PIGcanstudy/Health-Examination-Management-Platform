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
#ifndef _QUERYPEOPLE_DO_
#define _QUERYPEOPLE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class QueryDO
{
	//�������Ա�֤�����롢���ա����䡢�Ƿ���䡢�ֻ�����
	CC_SYNTHESIZE(string, person_name, personName);
	CC_SYNTHESIZE(string, sex, Sex);
	CC_SYNTHESIZE(string, id_card, idCard);
	CC_SYNTHESIZE(string, birth, Birth);
	CC_SYNTHESIZE(int, age, Age);
	CC_SYNTHESIZE(string, is_marry, isMarry);
	CC_SYNTHESIZE(string, mobile, Mobile);
public:
	QueryDO() {
		person_name = "";
		sex = "";
		id_card = "";
		birth = "";
		age = 999;
		is_marry = "";
		mobile = "";
	}
};

#endif // !_QUERYPEOPLE_DO_
