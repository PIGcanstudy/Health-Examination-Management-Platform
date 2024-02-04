import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  getDictnameListApi,
  getJobnameListApi,
  getPackageProlistApi,
  getPackagePronamelistApi,
  getPlannameListApi,
  getPlanProlistApi,
  getSelectionnameListApi,
  getTermnameListApi,
  getTypeTreeApi,
  getUesrnameListApi
} from '@/apis/public/index.js'

export const usePublicStore = defineStore('public', () => {
// 重写方法
//获取字典数据名称列表（用于输入表单下拉列表）
const getDictnameList = async (params) => {
  return await getDictnameListApi(params)
}
//获取工种名称列表（分页＋条件）
const getJobnameList = async (params) => {
  return await getJobnameListApi(params)
}
//获取组合项目列表（条件＋分页）
const getPackageProlist = async (params) => {
  return await getPackageProlistApi(params)
}
//获取组合项目名称列表（用于输入表单下拉列表）
const getPackagePronamelist = async (params) => {
  return await getPackagePronamelistApi(params)
}
//获取套餐名称列表（条件+分页）
const getPlannameList = async (params) => {
  return await  getPlannameListApi(params)
}
//获取套餐组合项目列表
const getPlanProlist = async (params) => {
  return await  getPlanProlistApi(params)
}
//科室名称列表
const getSelectionnameList = async (params) => {
  return await  getSelectionnameListApi(params)
}
const getTermnameList = async (params) => {
  return await  getTermnameListApi(params)
}
const getTypeTree = async (params) => {
  return await  getTypeTreeApi(params)
}
const getUesrnameList = async (params) => {
  return await  getUesrnameListApi(params)
}


  // 暴露出的数据
  return {
    getDictnameList,
    getJobnameList,
    getPackageProlist,
    getPackagePronamelist,
    getPlannameList,
    getPlanProlist,
    getSelectionnameList,
    getTermnameList,
    getTypeTree,
    getUesrnameList
  }
})
