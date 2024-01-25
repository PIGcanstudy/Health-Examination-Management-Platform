#pragma once
#ifndef _HealthCertiListQuery_
#define _HealthCertiListQuery_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class HealthCertiListQuery : public PageQuery
{
	DTO_INIT(HealthCertiListQuery, PageQuery);
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.name");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.sex");
	}
	// 年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.age");
	}
	// 打印状态
	DTO_FIELD(UInt32, print_statu);
	DTO_FIELD_INFO(print_statu) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.print_statu");
	}
	// 登记时间
	DTO_FIELD(String, register_date);
	DTO_FIELD_INFO(register_date) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.register_date");
	}
	// 上传状态
	DTO_FIELD(UInt32, upload_statu);
	DTO_FIELD_INFO(upload_statu) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.upload_statu");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_