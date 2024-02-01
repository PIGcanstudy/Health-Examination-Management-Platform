#pragma once
#ifndef _SAVE_INFO_DO_H_
#define _SAVE_INFO_DO_H_
#include "../DoInclude.h"

/**
 * 测试菜单数据库实体
 */
class SaveInfoDO
{
	// 身份证号
	CC_SYNTHESIZE(string, id_card, Id_card);
	//姓名
	CC_SYNTHESIZE(string, person_name, Person_name);
	//性别
	CC_SYNTHESIZE(string, sex, Sex);
	//年龄
	CC_SYNTHESIZE(int, age, Age);
	//联系电话
	CC_SYNTHESIZE(string, mobile, Mobile);
	//婚姻状态
	CC_SYNTHESIZE(string, is_marry, Is_marry);
public:
	SaveInfoDO() {}
	SaveInfoDO(string id_card, string person_name, string sex, int age, string mobile,string is_marry)
	{
		this->id_card = id_card;
		this->person_name = person_name;
		this->sex = sex;
		this->age = age;	
		this->mobile = mobile;
		this->is_marry = is_marry;
	}
};


#endif // !_SAVE_INFO_DO_H_