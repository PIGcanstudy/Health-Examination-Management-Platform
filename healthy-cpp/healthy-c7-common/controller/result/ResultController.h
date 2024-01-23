#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-18

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
#ifndef _RESULTCONTROLLER_H_
#define _RESULTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/query/result/ResultQuery.h"
#include"../../domain/dto/result/ResultDTO.h"
#include"../../domain/vo/result/ResultVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ResultController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(ResultController);
public: //����ӿ�

	//1.1��Ŀ���۲�ѯ�ӿ�����
	ENDPOINT_INFO(queryResult) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("result.query.list"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ResultPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//��ԱID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("result.field.personId"), "007", true);
	}
	//1.2��Ŀ���۲�ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/result/depart-result", queryResult, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ�ͣ�����Browser���Query��
		API_HANDLER_QUERY_PARAM(resultQuery, ResultQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPrimCheck(resultQuery));
	}
private: //����ӿ�ִ�к���
	ResultPageJsonVO::Wrapper execQueryPrimCheck(const ResultQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_RESULTCONTROLLER_H_