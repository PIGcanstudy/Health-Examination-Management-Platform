#include "stdafx.h"
#include "PackagesListController.h"
#include "../../service/packageslist/PackagesListApiClient.h"
#include "../ApiDeclarativeServicesHelper.h"


PackagesListPageJsonVO::Wrapper PackagesListController::execQueryPackagesList(const String& keywords, const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, PackagesListApiClient, "packageslist-api");
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	//return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->name))->readBodyToDto<SamplePageJsonVO::Wrapper>(om);
	return {};
}
