#include "UploadMoreController.h"
#include "stdafx.h"
#include <iostream>
// FastDFS使用需要的相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

StringJsonVO::Wrapper UploadMoreController::execUploadHealthCertiMore(const List<UploadMoreDTO::Wrapper>& dtoArray)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	auto& dtos = *dtoArray.get();
	for (auto i = dtos.begin(); i != dtos.end(); i++)
	{
		UploadMoreDTO::Wrapper dto = *i;
		// 参数校验
		if (!dto->fileName)
		{
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义DFS客户端对象和URL前缀
		ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
		//文件上传
		std::string fieldname = client.uploadFile(dto->fileName);
		std::cout << "upload fieldname is : " << fieldname << std::endl;
		// 构建下载路径
		std::string downloadUrl = urlPrefix + fieldname;
		// 输出下载路径
		std::cout << "download url: " << downloadUrl << std::endl;
		// 判断是否上传成功
		if (!fieldname.empty()) {
			jvo->success(dto->fileName);
		}
		else
		{
			jvo->fail(dto->fileName);
		}
		// 响应结果
	}
	return jvo;
}
