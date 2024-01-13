#include "stdafx.h"
#include "GroupPersonController.h"

StringJsonVO::Wrapper GroupPersonController::execQueryTest(const PageQuery::Wrapper& pq)
{
	StringJsonVO::Wrapper vo = StringJsonVO::createShared();
	if (pq->pageIndex == 1)
	{
		vo->success(String(ZH_WORDS_GETTER("test.field.succ")));
	}
	else
	{
		vo->fail(String(ZH_WORDS_GETTER("test.field.fail")));
	}
	return vo;
}
