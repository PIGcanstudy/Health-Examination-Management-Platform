#pragma once
#ifndef _GROUP_PERSON_INFO_DTO_
#define _GROUP_PERSON_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 人员详情传输数据对象实体
 */
class GroupPersonInfoDTO : public oatpp::DTO
{
	DTO_INIT(GroupPersonInfoDTO, DTO);
	//是否通过检查
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("group_person.field.is_pass"));

	// 体检编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("group_person.field.id"));

	// 身份证号
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("group_person.field.id_card"));
	
	// 姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("group_person.field.name"));

	// 性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("group_person.field.sex"));

	// 年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("group_person.field.age"));
	
	// 体检类型
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("group_person.field.physical_type"));
	
	// 订单类型
	API_DTO_FIELD_DEFAULT(UInt32, sporadic_physical, ZH_WORDS_GETTER("group_person.field.sporadic_physical"));
	
	// 危害因素
	API_DTO_FIELD_DEFAULT(String, hazard_factors, ZH_WORDS_GETTER("group_person.field.hazard_factors"));
	
	// 检查种类
	API_DTO_FIELD_DEFAULT(String, jc_type, ZH_WORDS_GETTER("group_person.field.jc_type"));

	// 单位名称
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("group_person.field.dept"));
	
	// 登记时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("group_person.field.create_time"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_PERSON_INFO_DTO_