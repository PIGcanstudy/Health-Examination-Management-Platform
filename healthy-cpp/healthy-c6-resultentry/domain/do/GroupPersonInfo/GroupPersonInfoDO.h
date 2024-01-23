#pragma once
#ifndef _GroupPerson_INFO_DO_
#define _GroupPerson_INFO_DO_
#include "../DoInclude.h"

class GroupPersonInfoDO
{

	//是否通过检查
	CC_SYNTHESIZE(int, is_pass, is_pass);

	// 体检编号
	CC_SYNTHESIZE(string, id, Id);

	// 身份证号
	CC_SYNTHESIZE(string, id_card, Id_Card);

	// 姓名
	CC_SYNTHESIZE(string, name, Name);

	// 性别
	CC_SYNTHESIZE(string, sex, Sex);

	// 年龄
	CC_SYNTHESIZE(int, age, Age);

	// 体检类型
	CC_SYNTHESIZE(string, physical_type, Physical_Type);

	// 订单类型
	CC_SYNTHESIZE(int, sporadic_physical, Sporadic_Physical);

	// 危害因素
	CC_SYNTHESIZE(string, hazard_factors, Hazard_Factors);

	// 检查种类
	CC_SYNTHESIZE(string, jc_type, Jc_Type));

	// 单位名称
	CC_SYNTHESIZE(string, dept, Dept);

	// 登记时间
	CC_SYNTHESIZE(string, create_time, Create_Time);

public:
	GroupPersonInfoDO() {
		is_pass = "1";
		id = "";
		id_card = "";
		name = "";
		sex = "";
		age = -1;
		physical_type = "";
		sporadic_physical = 1;
		hazard_factors = "";
		jc_type = "";
		dept = "";
		create_time = "";
	}
};

#endif // !_GroupPerson_INFO_DO_
