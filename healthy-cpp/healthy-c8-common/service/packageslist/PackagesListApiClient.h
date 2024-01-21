#pragma once

#ifndef _PackagesListApiClient_H_
#define _PackagesListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��ȡ�����Ŀ�б�ApiClient��������ʽ����
 */
class PackagesListApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(PackagesListApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "/common/query-packageslist", queryPackagesList, API_HANDLER_AUTN_HEADER, QUERY(String, keywords));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};


#endif