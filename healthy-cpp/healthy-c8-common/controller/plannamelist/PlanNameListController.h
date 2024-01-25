#pragma once
#ifndef _PlanNameListController_
#define _PlanNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/plannamelist/PlanNameListQuery.h"
#include "domain/dto/plannamelist/PlanNameListDTO.h"
#include "domain/vo/plannamelist/PlanNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PlanNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PlanNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryPlanNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("plannamelist.query-plannamelist.summary"), PlanNameListPageJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(String, "keyword", ZH_WORDS_GETTER("plannamelist.field.keyword"), "", false);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/common/query-plannamelist", queryPlanNameList, QUERY(String, keyword), execQueryPlanNameList(keyword, authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������2
	PlanNameListPageJsonVO::Wrapper execQueryPlanNameList(const String& keyword, const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif