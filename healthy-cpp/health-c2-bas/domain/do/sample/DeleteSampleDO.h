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
#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class SampleDO
{
	//是否删除(0-未删除，1-已删除)del_flag
	CC_SYNTHESIZE(int, del_flag, Del_flag);
	// 创建人create_id
	CC_SYNTHESIZE(int, create_id, Create_id);
	// 创建时间create_time
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 修改人update_id
	CC_SYNTHESIZE(int, update_id, Update_id);
	// 修改时间update_time
	CC_SYNTHESIZE(string, update_time, Update_time);
	// 删除人delete_id
	CC_SYNTHESIZE(int, delete_id, Delete_id);
	// 删除时间delete_time
	CC_SYNTHESIZE(string, delete_time, Delete_time);
	// 所属部门department_id
	CC_SYNTHESIZE(int, department_id, Department_id);
public:
	SampleDO() {
		del_flag = 0;
		create_id = 0;
		create_time = "";
		update_id = 0;
		update_time = "";
		delete_id = 0;
		delete_time = "";
		department_id = 0;

	}
};

#endif // !_SAMPLE_DO_
