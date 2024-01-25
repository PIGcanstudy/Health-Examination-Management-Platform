#pragma once
#ifndef _ViewExceptionController_
#define _ViewExceptionController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/viewexception/ViewExceptionDTO.h"
#include "domain/vo/viewexception/ViewExceptionVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ViewExceptionController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ViewExceptionController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryViewException) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("viewexception.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ViewExceptionJsonVO);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/healthcertificate-manage/query-viewexception", queryViewException, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryViewException(authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ViewExceptionJsonVO::Wrapper execQueryViewException(const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_