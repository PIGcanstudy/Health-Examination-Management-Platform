#pragma once
#ifndef _REVIEW_SERVICE_
#define _REVIEW_SERVICE_
#include <list>
#include "domain/vo/review/ReviewVO.h"
#include "domain/query/review/ReviewQuery.h"
#include "domain/dto/review/ReviewListDTO.h"

/**
 * �����ĸ����¼����ʵ��
 */
class ReviewService
{
public:
	// ��ҳ��ѯ��������
	ReviewListPageDTO::Wrapper listAll(const ReviewQuery::Wrapper& query);
	//�����ɾ����������������
	// ��������  ����   //��AddNewItems��ʵ�� ���ӹ��ܣ��˴�Ӧɾ��
	//uint64_t saveData(const ReviewListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ReviewListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);
};

#endif // !_REVIEW_SERVICE_