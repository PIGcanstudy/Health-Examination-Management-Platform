#ifndef _DeleteTBP_DO_
#define _DeleteTBP_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class DeleteTBPDO
{
    // 
    CC_SYNTHESIZE(string, code, Code);
    // ����
    CC_SYNTHESIZE(string, del_flag, Del_flag);


public:
    DeleteTBPDO() {
        code = "";
        del_flag = "";
    }
};
#endif // !_DeleteTBP_DO_