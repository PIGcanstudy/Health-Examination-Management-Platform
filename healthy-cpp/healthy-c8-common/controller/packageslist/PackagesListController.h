#ifndef _PACKAGESLIST_CONTROLLER_
#define _PACKAGESLIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/packageslist/PackagesListQuery.h"
#include "domain/dto/packageslist/PackagesListDTO.h" 
#include "domain/vo/packageslist/PackagesListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 公用服务接口控制器，演示基础接口的使用
 */
class PackagesListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PackagesListController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口1描述
	ENDPOINT_INFO(queryPackagesList) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("query-packageslist.get.summary"), PackagesListPageJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("query-packageslist.field.keywords"), "", true);
	}
	// 3.2 定义测试声明式服务调用的接口1处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/common/query-packageslist", queryPackagesList, QUERY(String, keywords), execQueryPackagesList(keywords, authObject->getPayload()));
private:
	PackagesListPageJsonVO::Wrapper execQueryPackagesList(const String& keywords, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif