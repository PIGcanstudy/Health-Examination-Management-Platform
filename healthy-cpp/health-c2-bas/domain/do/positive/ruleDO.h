#ifndef _RULE_DO_
#define _RULE_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class ruleDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// ��Ŀ����
	CC_SYNTHESIZE(string, projectName, ProjectName);
	//����
	CC_SYNTHESIZE(string, type, Type);
	// ����ֵ
	CC_SYNTHESIZE(string, regularValue, RegularValue);
	//���Թ���Id 
	CC_SYNTHESIZE(string, positiveResultId, PositiveResultId);
public:
	ruleDO() {
		id = "0";
		projectName = "";
		type = "";
		regularValue = "";
		positiveResultId = "";
	}
};

#endif // !_RULE_DO_