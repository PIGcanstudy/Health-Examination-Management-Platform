#include "stdafx.h"
#include "PackagesListController.h"
#include "../../service/packageslist/PackagesListApiClient.h"
#include "../ApiDeclarativeServicesHelper.h"


PackagesListPageJsonVO::Wrapper PackagesListController::execQueryPackagesList(const String& keywords, const PayloadDTO& payload)
{
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, PackagesListApiClient, "packageslist-api");
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// ���ز�ѯ���
	//return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->name))->readBodyToDto<SamplePageJsonVO::Wrapper>(om);
	return {};
}
