/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:02:34

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "StringUtil.h"
#include "ServerInfo.h"
#include "HttpServer.h"
#include "controller/Router.h"
#include "controller/OtherComponent.hpp"
#include "DbInit.h"
#ifdef HTTP_SERVER_DEMO
#include "uselib/jwt/TestToken.h"
#endif

#ifdef LINUX
#include "NacosClient.h"
#endif
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include "uselib/rocketmq/TestRocket.h"

#include "MongoClient.h"
#include <iostream>
#include <bsoncxx/json.hpp>

#include "RedisClient.h"
#include "uselib/sms/TestAliSms.h"
#include "EmailSender.h"
#include "uselib/pdf/TestPdf.h"

// �Ƿ��Ƿ���Swagger�ĵ���
#ifndef _RELEASE_DOC_
// �鿴Swagger�ĵ���ʱ����Ҫ�������ݿ⣬�⿪�����ע�͹ر������������ݿ�
//#define _RELEASE_DOC_
#endif

/**
 * ������������
 * ע�⣺
 * ������������Ҫ����һ���ĸ�ʽ���磺sp=8090��sn=feign-cpp-sample
 * ǰ׺����ʵֵ֮��ʹ��=�ָ�
 */
bool getStartArg(int argc, char* argv[]) {
	// �������˿�
	std::string serverPort = "8090";
	// ���ݿ�������Ϣ
	std::string dbUsername = "root";
	std::string dbPassword = "123456";
	std::string dbName = "test";
	std::string dbHost = "192.168.220.128";
	int dbPort = 3306;
	int dbMax = 5;
#ifdef LINUX
	// Nacos���ò���
	std::string nacosAddr = "192.168.220.128:8848";
	std::string nacosNs = "4833404f-4b82-462e-889a-3c508160c6b4";
	std::string serviceName = "";
	std::string regIp = "";
#endif

	// ��ʼ����
	int currIndex = 1;
	bool isSetDb = false;
	while (currIndex < argc)
	{
		// ����ַ���
		auto args = StringUtil::split(argv[currIndex], "=");
		// �жϲ����Ƿ�Ϸ�
		if (args.size() != 2)
		{
			cout << "arg: " << argv[currIndex] << ", format error." << endl;
			exit(1);
		}

		// ���ݲ���ǰ׺�Բ�ͬ���Ը�ֵ
		std::string prefix = args[0];
		std::string val = args[1];
		if (prefix == "sp") serverPort = val;
		else if (prefix == "du")
		{
			isSetDb = true;
			dbUsername = val;
		}
		else if (prefix == "dp")
		{
			isSetDb = true;
			dbPassword = val;
		}
		else if (prefix == "dn")
		{
			isSetDb = true;
			dbName = val;
		}
		else if (prefix == "dh")
		{
			isSetDb = true;
			dbHost = val;
		}
		else if (prefix == "dP")
		{
			isSetDb = true;
			dbPort = atoi(val.c_str());
		}
		else if (prefix == "dm") dbMax = atoi(val.c_str());
#ifdef LINUX
		else if (prefix == "na") nacosAddr = val;
		else if (prefix == "ns") nacosNs = val;
		else if (prefix == "sn") serviceName = val;
		else if (prefix == "ip") regIp = val;
#endif
		// ��������
		currIndex++;
	}

	// ��¼���������õ��ڴ��з���ʹ��
	ServerInfo::getInstance().setServerPort(serverPort);
	ServerInfo::getInstance().setDbUsername(dbUsername);
	ServerInfo::getInstance().setDbPassword(dbPassword);
	ServerInfo::getInstance().setDbName(dbName);
	ServerInfo::getInstance().setDbHost(dbHost);
	ServerInfo::getInstance().setDbPort(dbPort);
	ServerInfo::getInstance().setDbMax(dbMax);
#ifdef LINUX
	ServerInfo::getInstance().setNacosAddr(nacosAddr);
	ServerInfo::getInstance().setNacosNs(nacosNs);
	ServerInfo::getInstance().setRegIp(regIp);
	ServerInfo::getInstance().setServiceName(serviceName);
#endif
	return isSetDb;
}

void testDfs(string fileName)
{
	// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	std::cout << "download url: " << downloadUrl << std::endl;

// #ifdef LINUX
// 	//����ͻ��˶���
// 	FastDfsClient client("conf/client.conf");
// #else
// 	//����ͻ��˶���
// 	FastDfsClient client("192.168.220.128");
// #endif
// 
// 	//�����ϴ�
// 	std::string fieldName = client.uploadFile(fileName);
// 	std::cout << "upload fieldname is : " << fieldName << std::endl;
// 	//��������
// 	if (!fieldName.empty())
// 	{
// 		std::string path = "./public/fastdfs";
// 		fileName = client.downloadFile(fieldName, &path);
// 		std::cout << "download savepath is : " << fileName << std::endl;
// 	}
// 	//����ɾ���ļ�
// 	if (!fieldName.empty())
// 	{
// 		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
// 	}
}

void testExcel()
{
	// ������������
	std::vector<std::vector<std::string>> data;
	stringstream ss;
	for (int i = 1; i <= 10; i++)
	{
		std::vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss.clear();
			ss << "pos(" << i << "," << j << ")";
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}

	// ���屣������λ�ú�ҳǩ����
	// ע�⣺�ļ������ƺ��ļ�·�����ܳ�������
	std::string fileName = "./public/excel/1.xlsx";
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫ�������ļ��л�ȡ
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			cout << cellVal << ",";
		}
		cout << endl;
	}

	// ���Դ����ڶ���ҳǩ
	sheetName = ZH_WORDS_GETTER("excel.sheet.s2");
	excel.writeVectorToFile(fileName, sheetName, data);

	// ���Ը��ǵ�һ��ҳǩ
	sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h1") ,
		ZH_WORDS_GETTER("excel.header.h2") ,
		ZH_WORDS_GETTER("excel.header.h3") ,
		ZH_WORDS_GETTER("excel.header.h4") ,
		ZH_WORDS_GETTER("excel.header.h5") ,
		});
	excel.writeVectorToFile(fileName, sheetName, data);
}

void testUseMongo()
{
	//�������Ӷ���
	ZO_CREATE_MONGO_CLIENT(mc);
	//��ӵ�������
	auto docBuilder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc = docBuilder
		<< "name" << "MongoDB"
		<< "type" << "database"
		<< "count" << 1
		<< "versions" << open_array
		<< "v3.2" << "v3.0" << "v2.6"
		<< close_array
		<< "info" << open_document
		<< "x" << 203
		<< "y" << 102
		<< close_document
		<< finalize;
	auto res = mc.addOne("t1", doc.view());
	if (res.type() != bsoncxx::type::k_null)
	{
		std::cout << res.get_oid().value.to_string() << std::endl;
	}

	//��Ӷ�������
	std::vector<bsoncxx::document::value> documents;
	for (int i = 0; i < 10; i++) {
		documents.push_back(bsoncxx::builder::stream::document{} << "i" << i << finalize);
	}
	int32_t addNum = mc.addMultiple("t2", documents);
	cout << "add data:" << addNum << endl;

	//ִ�в�ѯ����
	mc.execute("t2",
		[](mongocxx::collection* collection) {
			auto cursor = collection->find({});
			for (auto doc : cursor) {
				cout << bsoncxx::to_json(doc) << endl;
			}
		});
}

void testUseRedis()
{
	// ����Redis�ͻ��˶���
	ZO_CREATE_REDIS_CLIENT(rc);
	// ���ֵ
	bool res = rc.execute<bool>(
		[](Redis* r) {
			return r->set("01", "star");
		});
	std::cout << res << std::endl;
	// ��ȡֵ
	string val = rc.execute<string>(
		[](Redis* r) {
			return r->get("01").value();
		});
	std::cout << val << std::endl;
}

void testMail()
{
	std::string topic = ZH_WORDS_GETTER("mail.topic");
	std::string body1 = ZH_WORDS_GETTER("mail.body1");
	std::string body2 = ZH_WORDS_GETTER("mail.body2");
	// �����ʼ����Ͷ���
	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.setCharset("utf8");
	emailSender.addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender.addCcEmailAddr("2949543550@qq.com", ZH_WORDS_GETTER("mail.revname"));
	emailSender.setEmailContent(topic, body1);
	emailSender.addAttachment("/home/file/1.zip");
	if (emailSender.send())
		std::cout << "mail send ok" << std::endl;
	else
		std::cout << "mail send fail" << std::endl;
}

int main(int argc, char* argv[]) {
#ifdef HTTP_SERVER_DEMO
	// �������� JWT Token
	TestToken::generateToken();
#endif

	// ������������ʼ��
	bool isSetDb = getStartArg(argc, argv);
	//testDfs("E:\\Images\\20141011112404344.jpg.source.jpg");
	//testExcel();
	//TestRocket tr;
	//tr.testRocket();
	//testUseMongo();
	//testUseRedis();
	//TestAliSms::test();
	//testMail();
	TestPdf::testText();
	TestPdf::testTpl();
#ifdef LINUX
	// ����Nacos�ͻ��˶���
	NacosClient nacosClient(
		ServerInfo::getInstance().getNacosAddr(),
		ServerInfo::getInstance().getNacosNs());
	// ��Nacos���������л�ȡ���ݿ�����
	if (!isSetDb)
	{
		YAML::Node node = nacosClient.getConfig("data-source.yaml");
		YamlHelper yaml;
		std::string dbUrl = yaml.getString(&node, "spring.datasource.url");
		if (dbUrl != "")
		{
			int dbPort = 0;
			std::string dbHost = "";
			std::string dbName = "";
			// �������ݿ������ַ���
			yaml.parseDbConnUrl(dbUrl, &dbHost, &dbPort, &dbName);
			// ��ȡ���ݿ��û���������
			std::string dbUsername = yaml.getString(&node, "spring.datasource.username");
			std::string dbPassword = yaml.getString(&node, "spring.datasource.password");
			// �����޸Ļ����е�����
			ServerInfo::getInstance().setDbUsername(dbUsername);
			ServerInfo::getInstance().setDbPassword(dbPassword);
			ServerInfo::getInstance().setDbName(dbName);
			ServerInfo::getInstance().setDbHost(dbHost);
			ServerInfo::getInstance().setDbPort(dbPort);
		}
	}

	// ע�����
	if (!ServerInfo::getInstance().getServiceName().empty() && !ServerInfo::getInstance().getRegIp().empty())
	{
		nacosClient.registerInstance(
			ServerInfo::getInstance().getRegIp(),
			atoi(ServerInfo::getInstance().getServerPort().c_str()),
			ServerInfo::getInstance().getServiceName());
	}
#endif

#ifndef _RELEASE_DOC_
	// ��ʼ���ݿ�����
	bool initConnPool = DbInit::initDbPool(DBConfig(
		ServerInfo::getInstance().getDbUsername(),
		ServerInfo::getInstance().getDbPassword(),
		ServerInfo::getInstance().getDbName(),
		ServerInfo::getInstance().getDbHost(),
		ServerInfo::getInstance().getDbPort(),
		ServerInfo::getInstance().getDbMax()));
	if (!initConnPool) return -1;
#endif

	// ����HTTP������
	HttpServer::startServer(ServerInfo::getInstance().getServerPort(),
		[=](Endpoints* doc, HttpRouter* router) {
			Router(doc, router).initRouter();
		},
		[](std::shared_ptr<AbstractComponentReg>* o) {
			*o = std::make_shared<OtherComponent>();
		});

#ifndef _RELEASE_DOC_
	// �ͷ����ݿ�����
	DbInit::releasePool();
#endif

#ifdef LINUX
	// ��ע�����
	if (!ServerInfo::getInstance().getServiceName().empty() && !ServerInfo::getInstance().getRegIp().empty())
	{
		nacosClient.deregisterInstance(
			ServerInfo::getInstance().getRegIp(),
			atoi(ServerInfo::getInstance().getServerPort().c_str()),
			ServerInfo::getInstance().getServiceName());
	}
#endif
	return 0;
}
