#pragma once
#ifndef _REVIEW_DAO_
#define _REVIEW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/review/ReviewDO.h"
#include "../../domain/query/review/ReviewQuery.h"

/**
 * �����¼�����ݿ����ʵ��
 */
class ReviewDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ReviewQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ReviewDO> selectWithPage(const ReviewQuery::Wrapper& query);
	// ͨ��������ѯ����
	//list<ReviewDO> selectByName(const string& name);
	//�˴�����Ҫ����Ķ����ɣ���������������������������������������
	// ��������    ��AddNewItems��ʵ�� ���ӹ��ܣ��˴�Ӧɾ��
	//uint64_t insert(const ReviewDO& iObj);
	// �޸�����
	//int update(const ReviewDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);//id��string����??????????????????????
};
#endif // !_REVIEW_DAO_