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
#ifndef _MEDEXAMPRINTREPORT_DO_
#define _MEDEXAMPRINTREPORT_DO_
#include "../DoInclude.h"

/**
 * 检测人员数据库实体类
 * 负责人：小智
 */
class MedExamPrintReportDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(uint32_t, age, Age);
	// 审核
	CC_SYNTHESIZE(bool, statu, Statu);
	// 打印
	CC_SYNTHESIZE(bool, printState, PrintState);
	// 零星检查
	CC_SYNTHESIZE(bool, sporadicPhysical, SporadicPhysical);

public:
	MedExamPrintReportDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		statu = false;
		printState = false;
		sporadicPhysical = false;
	}
};

#endif // !_MEDEXAMPRINTREPORT_DO_
