#pragma once
#ifndef _REVIEW_H_
#define _REVIEW_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 
 */
class Review : public PageQuery
{
	DTO_INIT(Review, DTO);
	//姓名
	API_DTO_FIELD_DEFAULT()
	//复查项目
	API_DTO_FIELD_DEFAULT()
	//复查说明
	
	//操作日期
	
	//登记日期
	
	//登记状态
	
	//危害因素
	
	//操作
	
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
	// 年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEW_H_