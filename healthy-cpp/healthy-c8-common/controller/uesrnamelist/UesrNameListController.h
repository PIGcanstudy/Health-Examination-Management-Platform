#pragma once
#ifndef _UesrNameListController_
#define _UesrNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/uesrnamelist/UesrNameListQuery.h"
#include "domain/dto/uesrnamelist/UesrNameListDTO.h"
#include "domain/vo/uesrnamelist/UesrNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class UesrNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UesrNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryUesrNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("uesrnamelist.query-uesrnamelist.summary"), UesrNameListJsonVO::Wrapper);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-uesrnamelist", queryUesrNameList, execQueryUesrNameList(authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������1
	UesrNameListJsonVO::Wrapper execQueryUesrNameList(const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif