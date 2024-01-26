#pragma once
#ifndef _ADDNEWITEMS_SERVICE_
#define _ADDNEWITEMS_SERVICE_
#include <list>
#include "domain/vo/addNewItems/AddNewItemsVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"

/**
 * ���������������¼����ʵ��
 */
class AddNewItemsService
{
public:
	//��ѯ��Review�н��У��˴�Ӧɾ��
	// ��ҳ��ѯ��������
	//AddNewItemsPageDTO::Wrapper listAll(const AddNewItemsQuery::Wrapper& query);
	// ��������  ����
	uint64_t saveData(const AddNewItemsDTO::Wrapper& dto);
	//�����ɾ����������������
	// �޸�����
	//bool updateData(const AddNewItemsDTO::Wrapper& dto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_ADDNEWITEMS_SERVICE_