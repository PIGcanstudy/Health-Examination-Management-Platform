#ifndef _RESRULE_DO_
#define _RESRULE_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class resRuleDO 
{
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, condition, Conditon);
	// �ʺ��Ա�
	CC_SYNTHESIZE(string, genderAppropriate, GenderAppropriate);
	// ����Id
	CC_SYNTHESIZE(string, positiveId, PositiveId);
	// ����
	CC_SYNTHESIZE(string, projectName, ProjectName);
	// �ж�����
	CC_SYNTHESIZE(string, judgmentCondition, JudgmentCondition);
	//�ų����Խ��
	CC_SYNTHESIZE(string, excludePositive, ExcludePositive);
	//����
	CC_SYNTHESIZE(string, type, Type);
public:
	resRuleDO() {
		id = "0";
		condition = "";
		genderAppropriate = "";
		positiveId = "";
		projectName = "";
		judgmentCondition = "";
		excludePositive = "";
		type = "";
	}
};

#endif // !_RESRULE_DO_