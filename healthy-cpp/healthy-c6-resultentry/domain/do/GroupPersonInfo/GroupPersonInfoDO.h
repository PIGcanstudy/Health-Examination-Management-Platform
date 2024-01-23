#pragma once
#ifndef _GroupPerson_INFO_DO_
#define _GroupPerson_INFO_DO_
#include "../DoInclude.h"

class GroupPersonInfoDO
{

	//�Ƿ�ͨ�����
	CC_SYNTHESIZE(int, is_pass, is_pass);

	// �����
	CC_SYNTHESIZE(string, id, Id);

	// ���֤��
	CC_SYNTHESIZE(string, id_card, Id_Card);

	// ����
	CC_SYNTHESIZE(string, name, Name);

	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);

	// ����
	CC_SYNTHESIZE(int, age, Age);

	// �������
	CC_SYNTHESIZE(string, physical_type, Physical_Type);

	// ��������
	CC_SYNTHESIZE(int, sporadic_physical, Sporadic_Physical);

	// Σ������
	CC_SYNTHESIZE(string, hazard_factors, Hazard_Factors);

	// �������
	CC_SYNTHESIZE(string, jc_type, Jc_Type));

	// ��λ����
	CC_SYNTHESIZE(string, dept, Dept);

	// �Ǽ�ʱ��
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
