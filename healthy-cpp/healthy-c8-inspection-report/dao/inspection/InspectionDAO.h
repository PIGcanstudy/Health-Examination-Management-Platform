#pragma once

#ifndef _INSPECTION_DAO_
#define _INSPECTION_DAO_

#include "BaseDAO.h"
#include "../../domain/do/inspection/InspectionDO.h"
#include "../../domain/query/inspection/InspectionQuery.h"

/**
 * �����б����ݿ����ʵ��
 */
class ReportListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ReportListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ReportListDO> selectWithPage(const ReportListQuery::Wrapper& query);

	// ͨ������Ų�ѯ����
	list<ReportListDO> selectByTest_num(const string& test_num);
	// ͨ����쵥λ��ѯ����
	list<ReportListDO> selectByPhysical_unit(const string& physical_unit);
	// ͨ�����֤�Ų�ѯ����
	list<ReportListDO> selectById_card(const string& id_card);
	// ͨ��������ڲ�ѯ����
	list<ReportListDO> selectByCheck_date(const string& check_date);
	// ͨ�����״̬��ѯ����
	list<ReportListDO> selectByStatu(const int& statu);
	// ͨ��������ѯ����
	list<ReportListDO> selectByName(const string& name);
	// ͨ���Ա��ѯ����
	list<ReportListDO> selectBySex(const string& sex);
	// ͨ�������ѯ����
	list<ReportListDO> selectByAge(const int& age);
};


#endif

