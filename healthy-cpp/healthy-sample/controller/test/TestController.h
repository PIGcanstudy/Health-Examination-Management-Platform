#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/07 22:34:20

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
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TestController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(TestController);
public: // ����ӿ�
	ENDPOINT_INFO(queryTest) {
		// ����ӿ�����
		info->summary = ZH_WORDS_GETTER("test.get.summary");
		// ����ӿ���Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, params)) {
		// ����ѯ����ת����PageQuery��ѯģ��
		API_HANDLER_QUERY_PARAM(pq, PageQuery, params);
		// ִ��ҵ���߼�����
		API_HANDLER_RESP_VO(execQueryTest(pq));
	}
private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& pq);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_TESTCONTROLLER_H_