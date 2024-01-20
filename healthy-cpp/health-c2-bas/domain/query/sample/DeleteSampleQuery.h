#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class DeleteSampleQuery : public PageQuery
{
	DTO_INIT(DeleteSampleQuery, PageQuery);
	//是否删除(0-未删除，1-已删除)del_flag
	DTO_FIELD(UInt32, del_flag);
	DTO_FIELD_INFO(del_flag) {
		info->description = ZH_WORDS_GETTER("sample.field.del_flag");
	}
	// 创建人create_id
	DTO_FIELD(String, create_id);
	DTO_FIELD_INFO(create_id) {
		info->description = ZH_WORDS_GETTER("sample.field.create_id");
	}
	// 创建时间create_time
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("sample.field.create_time");
	}
	// 修改人update_id
	DTO_FIELD(UInt32, update_id);
	DTO_FIELD_INFO(update_id) {
		info->description = ZH_WORDS_GETTER("sample.field.update_id");
	}
	// 修改时间update_time
	DTO_FIELD(String, update_time);
	DTO_FIELD_INFO(update_time) {
		info->description = ZH_WORDS_GETTER("sample.field.update_time");
	}
	// 删除人delete_id
	DTO_FIELD(UInt32, delete_id);
	DTO_FIELD_INFO(delete_id) {
		info->description = ZH_WORDS_GETTER("sample.field.delete_id");
	}
	// 删除时间delete_time
	DTO_FIELD(String, delete_time);
	DTO_FIELD_INFO(delete_time) {
		info->description = ZH_WORDS_GETTER("sample.field.delete_time");
	}
	// 所属部门department_id
	DTO_FIELD(UInt32, department_id);
	DTO_FIELD_INFO(department_id) {
		info->description = ZH_WORDS_GETTER("sample.field.department_id");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
