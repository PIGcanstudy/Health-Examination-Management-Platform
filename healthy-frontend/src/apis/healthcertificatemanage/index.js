import Request from '@/apis/request.js'
const baseUrl = ''

//获取健康证详情
export const downloadHelthcertidetail = (params) => {
    return Request.requestJson(
        Request.GET,
        baseUrl + '',
        params
    )
}

//获取健康证列表
export const queryHerlthcertiList = (params) => {
    return Request.requestJson(
        Request.GET,
        baseUrl + '',
        params
    )
}

//打印确认（支持批量）
export const modifyPrintConfirm = (params) => {
    return Request.requestJson(
        Request.PUT,
        baseUrl + '',
    )
}

//批量打印（批量打印）
export const queryHelthcertiList = (params) => {
    return Request.requestJson(
        Request.PUT,
        baseUrl + '',
    )
}

//批量上传
export const uploadMore = (params) => {
    return Request.requestJson(
        Request.POST,
        baseUrl + '',
    )
}

//查看异常
export const queryViewException = (params) => {
    return Request.requestJson(
        Request.GET,
        baseUrl + '',
    )
}