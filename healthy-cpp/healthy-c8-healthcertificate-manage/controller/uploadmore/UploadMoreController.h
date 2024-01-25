#pragma once
#ifndef _UploadMoreController_
#define _UploadMoreController_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class UploadMoreController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(UploadMoreController);
public:

	// ����һ�����ļ��ϴ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("uploadmore.upload-more.summary"), uploadHealthCertiMore, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/healthcertificate-manage/upload-more", uploadHealthCertiMore, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadHealthCertiMore(request));

private: // ����ӿ�ִ�к���
	// ִ�ж��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadHealthCertiMore(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_