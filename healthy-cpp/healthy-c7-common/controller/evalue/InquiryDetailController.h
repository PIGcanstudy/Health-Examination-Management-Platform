#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/01/19

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _INQUIRYDETAIL_CONTROLLER_
#define _INQUIRYDETAIL_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "../healthy-c7-common/domain/query/evalue/InquiryDetailQuery.h"
#include "../healthy-c7-common/domain/dto/evalue/InquiryDetailDTO.h"
#include "../healthy-c7-common/domain/vo/evalue/InquiryDetailVO.h"
#include "../../../arch-demo/controller/file/FileController.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����������ʾ�����ӿڵ�ʹ��
 */
class InquiryDetailController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(InquiryDetailController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryInquiryDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inquiry.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InquiryDetailPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//����
		API_DEF_ADD_QUERY_PARAMS(UInt32, "workYear", ZH_WORDS_GETTER("inquiry.field.workYear"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "workMonth", ZH_WORDS_GETTER("inquiry.field.workMonth"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "maritalStatus", ZH_WORDS_GETTER("inquiry.field.maritalStatus"), u8"�ѻ�", true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "needYear", ZH_WORDS_GETTER("inquiry.field.needYear"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "needmonth", ZH_WORDS_GETTER("inquiry.field.needMonth"), 1, true);
		//�Ǳ���
		API_DEF_ADD_QUERY_PARAMS(String, "culture", ZH_WORDS_GETTER("inquiry.field.culture"), u8"��ѧ", false);
		API_DEF_ADD_QUERY_PARAMS(String, "homeAddress", ZH_WORDS_GETTER("inquiry.field.homeAddress"), u8"����", false);
		API_DEF_ADD_QUERY_PARAMS(String, "jobName", ZH_WORDS_GETTER("inquiry.field.jobName"), u8"ѧ��", false);
		API_DEF_ADD_QUERY_PARAMS(String, "jobOrderName", ZH_WORDS_GETTER("inquiry.field.jobOrderName"), u8"��ʦ", false);
		API_DEF_ADD_QUERY_PARAMS(String, "department", ZH_WORDS_GETTER("inquiry.field.department"), u8"ѧ����", false);

	} 
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/evalue/inquiry-detail", queryInquiryDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(idq, InquiryDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryInquiryDetail(idq));
	}


private:
	InquiryDetailJsonVO::Wrapper execQueryInquiryDetail(const InquiryDetailQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif  _SAMPLE_CONTROLLER_