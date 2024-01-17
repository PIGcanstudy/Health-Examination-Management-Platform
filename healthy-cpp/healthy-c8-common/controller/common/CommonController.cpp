#include "stdafx.h"
#include "CommonController.h"
#include "../../service/common/PackagesListApiClient.h"
#include "../ApiDeclarativeServicesHelper.h"


PackagesListPageJsonVO::Wrapper CommonController::execQueryPackagesList(const String& keywords, const PayloadDTO& payload)
{
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, PackagesListApiClient, "packageslist-api");
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// ���ز�ѯ���
	//return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->name))->readBodyToDto<SamplePageJsonVO::Wrapper>(om);
	return {};
}
