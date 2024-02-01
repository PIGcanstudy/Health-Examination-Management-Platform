import Request from '@/apis/request.js'
const baseUrl = ''

//获取字典数据名称列表（用于输入表单下拉列表）
export const querydictnamelist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}

//获取工种名称列表（分页＋条件）
export const queryjobnamelist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}

//获取组合项目列表（条件＋分页）
export const querypackageprolist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}

//获取组合项目名称列表（用于输入表单下拉列表）
export const querypackagepronamelist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}

//获取套餐名称列表（条件+分页）
export const queryplannamelist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}

//获取套餐组合项目列表
export const queryplanprolist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}

//科室名称列表
export const queryselectionnamelist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}


//获取术语名称列表（条件+分页）
export const querytermnamelist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}


//获取类型树
export const querytypetree = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}

//获取用户名称列表（用于输入表单下拉列表框）
export const queryuesrnamelist = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/',
    params
  )
}