#pragma once
#ifndef _INTERRO_DO_
#define _INTERRO_DO_
#include"../DoInclude.h"

/**
* ���ݿ�ʵ����
*/
class InterroDO
{
	// ����˱��
	CC_SYNTHESIZE(string, id, Id);
	// �����Ŀ
	CC_SYNTHESIZE(string, project, Project);
	// Σ���̶�
	CC_SYNTHESIZE(string, degree, Degree);
	// ʱ��
	CC_SYNTHESIZE(string, time, Time);
public:
	InterroDO() {
		id = "";
		project = "";
		degree = "";
		time = "";
	}
};

#endif //_INTERRO_DO_