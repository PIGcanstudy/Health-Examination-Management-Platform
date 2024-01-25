#pragma once
#ifndef _ADDNEWITEMS_DAO_
#define _ADDNEWITEMS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/addNewItems/AddNewItemsDO.h"
#include "../../domain/query/addNewItems/AddNewItemsQuery.h"

/**
 * ���������¼�����ݿ����ʵ��
 */
class AddNewItemsDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const AddNewItemsQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<AddNewItemsDO> selectWithPage(const AddNewItemsQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<AddNewItemsDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const AddNewItemsDO& iObj);
	// �޸�����
	//int update(const AddNewItemsDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);//id��string����??????????????????????
};
#endif // !_ADDNEWITEMS_DAO_