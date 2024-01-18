#pragma once
#ifndef _REVIEWListDTO_H_
#define _REVIEWListDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  �����¼�б������ݶ���ʵ��
*/
class ReviewListDTO : public oatpp::DTO
{
	DTO_INIT(ReviewListDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("review.field.id"));
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("review.field.personName"));
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("review.field.personId"));
	//������Ŀcheck_project_id varchar(50)
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("review.field.checkProjectId"));
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("review.field.checkProjectName"));
	//����˵��review_explain varchar(255)
	API_DTO_FIELD_DEFAULT(String, reviewExplain, ZH_WORDS_GETTER("review.field.reviewExplain"));
	//��������review_time` datetime '��������'
	API_DTO_FIELD_DEFAULT(String, reviewTime, ZH_WORDS_GETTER("review.field.reviewTime"));
	//�Ǽ�����create_time datetime '��������'
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("review.field.createTime"));
	//�Ǽ�״̬state int '���״̬
	API_DTO_FIELD_DEFAULT(UInt64, state, ZH_WORDS_GETTER("review.field.state"));
	//Σ������hazard_factor_code varchar(255)
	API_DTO_FIELD_DEFAULT(String, hazardFactorCode, ZH_WORDS_GETTER("review.field.hazardFactorCode"));
	//����

};

/**
*  �����б��ҳ����ʵ��
*/
class ReviewListPageDTO : public PageDTO<ReviewListDTO::Wrapper> {
	DTO_INIT(ReviewListPageDTO, PageDTO<ReviewListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEWListDTO_H_