#pragma once
#ifndef _SAVE_INFO_CONTROLLER_H_
#define _SAVE_INFO_CONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/Exalanding/SaveInfoQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/Exalanding/SaveInfoVO.h"
#include "domain/dto/Exalanding/SaveInfoDTO.h"
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SaveInfoController : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(SaveInfoController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(querySample) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("exalanding.saveinfo.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SaveInfoPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/exaLanding-saveinfo", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, SaveInfoQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUserInfo(userQuery, authObject->getPayload()));
	}
	
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	SaveInfoPageJsonVO::Wrapper execQueryUserInfo(const SaveInfoQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _SAVE_INFO_CONTROLLER_H_