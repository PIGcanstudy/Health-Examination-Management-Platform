#pragma once

#ifndef _PackagesListApiClient_H_
#define _PackagesListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 获取组合项目列表ApiClient定义声明式服务
 */
class PackagesListApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{
	// 3 定义ApiClient控制器使用宏---开始
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 初始化定义
	API_CLIENT_INIT(PackagesListApiClient);

	// 5 使用API_CALL或API_CALL_ASYNC声明调用服务接口

	// 通过ID查询
	API_CALL(API_M_GET, "/common/query-packageslist", queryPackagesList, API_HANDLER_AUTN_HEADER, QUERY(String, keywords));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 取消ApiClient控制器使用宏---结束
};


#endif