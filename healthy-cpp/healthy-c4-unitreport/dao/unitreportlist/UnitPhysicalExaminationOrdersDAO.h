#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_DAO_
#define _UNITPHYSICALEXAMINATIONORDERS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unitreportlist/UnitPhysicalExaminationOrdersDO.h"
#include "../../domain/query/unitreportlist/UnitPhysicalExaminationOrdersQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class UnitPhysicalExaminationOrdersDAO : public BaseDAO
{
public:
	// ��ҳ��ѯ����
	list<UnitPhysicalExaminationOrdersDO> selectWithPage(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);
	// ͨ����λ���ƺͶ���ǩ�������ѯ����
	list<UnitPhysicalExaminationOrdersDO> selectByName(const string& name , const string& beginTime, const string& endTime);
};
#endif // !_SAMPLE_DAO_