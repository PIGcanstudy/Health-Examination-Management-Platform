#pragma once
#ifndef _REVIEW_H_
#define _REVIEW_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 
 */
class Review : public PageQuery
{
	DTO_INIT(Review, DTO);
	//����
	API_DTO_FIELD_DEFAULT()
	//������Ŀ
	API_DTO_FIELD_DEFAULT()
	//����˵��
	
	//��������
	
	//�Ǽ�����
	
	//�Ǽ�״̬
	
	//Σ������
	
	//����
	
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
	// ����
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEW_H_