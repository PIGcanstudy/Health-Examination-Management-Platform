import Request from '@/apis/request.js'
const baseUrl = ''
// 获取工种名称列表
export const queryJobName = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}
