#include "stdafx.h"
#include <iostream>
#include "UpFileController.h"
#include "../../service/file_chengfeng/UpFileService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "upfastDFS/UpFileDFS.h"
StringJsonVO::Wrapper UpFileController::execModifySample(const UpFileDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	//return Uint64JsonVO::Wrapper();
	
	 //定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	jvo->fail(ZH_WORDS_GETTER("file_chengfeng.field.fail"));
	// 参数校验
	if (!dto->id)
	{
		jvo->fail(ZH_WORDS_GETTER("file_chengfeng.field.fail"));
		return jvo;
	}

	//上传文件是否为.zip
	string testZip;
	testZip = dto->url->substr(dto->url->size() - 4, 4);
	if (testZip == ".zip") {
		//获得DFS中文件下载地址
		UpFileDFS dfs;
		string download = dfs.testDfs(dto->url);
		//string download = dfs.testDfsWithConf(dto->url);


		// 定义一个Service
		UpFileService service;
		//// 执行数据修改
		if (service.updateData(dto, download, payload)) {
			jvo->success(ZH_WORDS_GETTER("file_chengfeng.field.success"));
		}
	}

	
	// //响应结果
	return jvo;


}


