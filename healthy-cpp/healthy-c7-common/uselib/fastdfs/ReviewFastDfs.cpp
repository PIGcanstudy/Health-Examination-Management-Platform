#ifdef USE_DFS

#include "stdafx.h"
#include <iostream>
#include "ReviewFastDfs.h"
// FastDFSʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

//void TestFastDfs::testDfs(string fileName)
//{
//#ifdef LINUX
//	//����ͻ��˶���
//	FastDfsClient client("conf/client.conf");
//#else
//	//����ͻ��˶���
//	FastDfsClient client("192.168.220.128");
//#endif
//
//	//�����ϴ�
//	std::string fieldName = client.uploadFile(fileName);
//	std::cout << "upload fieldname is : " << fieldName << std::endl;
//	//��������
//	if (!fieldName.empty())
//	{
//		std::string path = "./public/fastdfs";
//		fileName = client.downloadFile(fieldName, &path);
//		std::cout << "download savepath is : " << fileName << std::endl;
//	}
//	//����ɾ���ļ�
//	if (!fieldName.empty())
//	{
//		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
//	}
//}

string ReviewFastDfs::ReviewDfsWithConf(string fileName)
{
//	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
//#ifdef LINUX
//	// ��ȡ�������ݽڵ�
//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
//	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
//	std::string config = ns.getConfigText("client.conf");
//	// ����ͻ��˶���
//	FastDfsClient client(config, false);
//#else
//	// ��ȡ�������ݽڵ�
//	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
//	// �������л�ȡFastDFS�ͻ�����������
//	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
//	std::string ip = ipPort.substr(0, ipPort.find(":"));
//	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
//	// ����ͻ��˶���
//	FastDfsClient client(ip, port);
//#endif
//	// ����urlǰ׺
//	std::string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	
	// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}

#endif // USE_DFS