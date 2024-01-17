#ifndef _COMMON_CONTROLLER_
#define _COMMON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/common/CommonQuery.h"
#include "domain/dto/common/CommonDTO.h" 
#include "domain/vo/common/CommonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���÷���ӿڿ���������ʾ�����ӿڵ�ʹ��
 */
class CommonController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CommonController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryPackagesList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("common.query-packageslist.summary"), PackagesListPageJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common.field.keywords"), "", true);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/common/query-packageslist", queryPackagesList, QUERY(String, keywords), execQueryPackagesList(keywords, authObject->getPayload()));
private:
	PackagesListPageJsonVO::Wrapper execQueryPackagesList(const String& keywords, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif