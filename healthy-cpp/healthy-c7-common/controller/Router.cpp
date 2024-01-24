/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/01/19

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
#include "Router.h"
#include "ApiHelper.h"

#include "Dangerous/DepartController.h"
#include "result/ResultController.h"
#include "info-inspectionSave/InfoController.h"
#include "Term/TermController.h"
#include "getUserName/UnitController.h"
#include "personDetail/DetailController.h"
#include "positive/positiveController.h"
#include "review/ReviewController.h"
#include "addNewItems/AddNewItemsController.h"
#include "id/IdController.h"
#include "personalReview/PersonalReviewController.h"
#include "downloadWord/DownloadWordController.h"
#include "groupItemIgno/GroupItemIgnoController.h"
#include "itemResult/ItemResultController.h"
#include "evalue/InquiryDetailController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"

#endif


#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(DepartController);
	ROUTER_SIMPLE_BIND(ResultController);
	ROUTER_SIMPLE_BIND(InfoController);
	ROUTER_SIMPLE_BIND(TermController);
	ROUTER_SIMPLE_BIND(PositiveConrtoller);
	ROUTER_SIMPLE_BIND(ItemResultController);
	ROUTER_SIMPLE_BIND(InquiryDetailController);
	ROUTER_SIMPLE_BIND(ReviewController);
	ROUTER_SIMPLE_BIND(AddNewItemsController);
	ROUTER_SIMPLE_BIND(IdController);
	ROUTER_SIMPLE_BIND(PersonalReviewController);
	ROUTER_SIMPLE_BIND(DownloadWordController);
	ROUTER_SIMPLE_BIND(GroupItemIgnoController);
	ROUTER_SIMPLE_BIND(DetailController);
	ROUTER_SIMPLE_BIND(UnitController);}
#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制器
	ROUTER_SIMPLE_BIND(FileController);
	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif