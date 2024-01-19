#ifndef _RESULTLISTDO_H_
#define _RESULTLISTDO_H_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class resultListDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ƿ��ض�
	CC_SYNTHESIZE(string, degree, Degree);
	// �Ƿ�����
	CC_SYNTHESIZE(string, positive, Positive);
	// ���ұ��
	CC_SYNTHESIZE(string, deptld, Deptld);
	// ְҵ����
	CC_SYNTHESIZE(string, advise, Advise);
	// ��������
	CC_SYNTHESIZE(string, healthAdvice, HealthAdvice);
private:
	resultListDO() {
		id = "0";
		name = "";
		degree = "";
		positive = "";
		deptld = "";
		advise = "";
		healthAdvice = "";
	}
};

#endif // !_RESULTLISTDO_H_