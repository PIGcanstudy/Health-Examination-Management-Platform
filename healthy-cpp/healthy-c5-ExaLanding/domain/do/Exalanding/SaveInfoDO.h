#pragma once
#ifndef _SAVE_INFO_DO_H_
#define _SAVE_INFO_DO_H_
#include "../DoInclude.h"

/**
 * ���Բ˵����ݿ�ʵ��
 */
class SaveInfoDO
{
	// ���֤��
	CC_SYNTHESIZE(string, id_card, Id_card);
	//����
	CC_SYNTHESIZE(string, person_name, Person_name);
	//�Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	//����
	CC_SYNTHESIZE(int, age, Age);
	//��ϵ�绰
	CC_SYNTHESIZE(string, mobile, Mobile);
	//����״̬
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