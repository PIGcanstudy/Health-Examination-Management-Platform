#pragma once
#ifndef _Person_DO_
#define _Person_DO_
#include "../DoInclude.h"

class PersonDO
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// �������
	CC_SYNTHESIZE(string, physical_type, Physical_type);



public:
	PersonDO() {
		name = "";
		sex = "";
		age = -1;
		physical_type = "";
	}
};

#endif // !_Person_DO_
