#include "UploadMoreController.h"
#include "stdafx.h"
#include <iostream>
// FastDFSʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

StringJsonVO::Wrapper UploadMoreController::execUploadHealthCertiMore(const List<UploadMoreDTO::Wrapper>& dtoArray)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	auto& dtos = *dtoArray.get();
	for (auto i = dtos.begin(); i != dtos.end(); i++)
	{
		UploadMoreDTO::Wrapper dto = *i;
		// ����У��
		if (!dto->fileName)
		{
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����DFS�ͻ��˶����URLǰ׺
		ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
		//�ļ��ϴ�
		std::string fieldname = client.uploadFile(dto->fileName);
		std::cout << "upload fieldname is : " << fieldname << std::endl;
		// ��������·��
		std::string downloadUrl = urlPrefix + fieldname;
		// �������·��
		std::cout << "download url: " << downloadUrl << std::endl;
		// �ж��Ƿ��ϴ��ɹ�
		if (!fieldname.empty()) {
			jvo->success(dto->fileName);
		}
		else
		{
			jvo->fail(dto->fileName);
		}
		// ��Ӧ���
	}
	return jvo;
}
